// COPYRIGHT 1995-2022 ESRI
// TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
// Unpublished material - all rights reserved under the
// Copyright Laws of the United States and applicable international
// laws, treaties, and conventions.
//
// For additional information, contact:
// Attn: Contracts and Legal Department
// Environmental Systems Research Institute, Inc.
// 380 New York Street
// Redlands, California 92373
// USA
//
// email: legal@esri.com
#include "ArcGISMapsSDK/Components/ArcGISLocationComponent.h"

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryEngine.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/Components/ArcGISMapComponent.h"

UArcGISLocationComponent::UArcGISLocationComponent() : Super()
{
	PrimaryComponentTick.bCanEverTick = true;

	bTickInEditor = true;
	bAutoActivate = true;

	bWantsOnUpdateTransform = true;
	bInternalHasChanged = true;
}

void UArcGISLocationComponent::BeginPlay()
{
	Super::BeginPlay();

	UpdateTransform();
}

void UArcGISLocationComponent::OnComponentCreated()
{
	bNeedsInitialization = true;
}

void UArcGISLocationComponent::OnUnregister()
{
	if (MapComponent.IsValid())
	{
		MapComponent->OnSpatialReferenceChanged.RemoveAll(this);
	}

	Super::OnUnregister();
}

void UArcGISLocationComponent::OnArcGISMapComponentChanged(UArcGISMapComponent* InMapComponent)
{
	if (MapComponent.IsValid() && MapComponent != InMapComponent)
	{
		MapComponent->OnSpatialReferenceChanged.RemoveAll(this);
	}

	if (MapComponent != InMapComponent)
	{
		MapComponent = InMapComponent;

		if (bNeedsInitialization)
		{
			UpdateGeoPositionAndRotation();
		}
	}

	if (MapComponent.IsValid())
	{
		// OnSpatialReferenceChanged gets serialized so we should make sure a unique binding exists
		if (!MapComponent->OnSpatialReferenceChanged.Contains(this, GET_FUNCTION_NAME_CHECKED(UArcGISLocationComponent, UpdateTransform)))
		{
			MapComponent->OnSpatialReferenceChanged.AddUniqueDynamic(this, &UArcGISLocationComponent::UpdateTransform);
		}

		if (!MapComponent->OnOriginPositionChanged.Contains(this, GET_FUNCTION_NAME_CHECKED(UArcGISLocationComponent, UpdateTransform)))
		{
			MapComponent->OnOriginPositionChanged.AddUniqueDynamic(this, &UArcGISLocationComponent::UpdateTransform);
		}
	}
}

UArcGISPoint* UArcGISLocationComponent::GetPosition() const
{
	return GetPosition_Internal();
}

FGeoPosition UArcGISLocationComponent::GetPosition_Internal() const
{
	return Position;
}

UArcGISRotation* UArcGISLocationComponent::GetRotation() const
{
	auto rotation = GetRotation_Internal();
	return UArcGISRotation::CreateArcGISRotation(rotation.Pitch, rotation.Roll, rotation.Heading);
}

FGeoRotation UArcGISLocationComponent::GetRotation_Internal() const
{
	return Rotation;
}

void UArcGISLocationComponent::OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport)
{
	Super::OnUpdateTransform(UpdateTransformFlags, Teleport);

	if (!bTransformHasChanged)
	{
		UpdateGeoPositionAndRotation();
	}

	bTransformHasChanged = false;
}

#if WITH_EDITORONLY_DATA
void UArcGISLocationComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	UpdateTransform();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void UArcGISLocationComponent::SetPosition(UArcGISPoint* InPosition)
{
	SetPosition_Internal(InPosition);
}

void UArcGISLocationComponent::SetPosition_Internal(const FGeoPosition& InPosition)
{
	if (Position == InPosition)
	{
		return;
	}

	Position = InPosition;

	bInternalHasChanged = true;
}

void UArcGISLocationComponent::SetRotation(UArcGISRotation* InRotation)
{
	FGeoRotation rotation;
	rotation.Pitch = InRotation->GetPitch();
	rotation.Heading = InRotation->GetHeading();
	rotation.Roll = InRotation->GetRoll();

	SetRotation_Internal(rotation);
}

void UArcGISLocationComponent::SetRotation_Internal(const FGeoRotation& InRotation)
{
	if (Rotation == InRotation)
	{
		return;
	}

	Rotation = InRotation;

	bInternalHasChanged = true;
}

void UArcGISLocationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if (bInternalHasChanged)
	{
		UpdateTransform();
	}
}

void UArcGISLocationComponent::UpdateTransform()
{
	if (MapComponent.IsValid() && MapComponent->ShouldEditorComponentBeUpdated() && MapComponent->HasSpatialReference())
	{
		FTransform EngineTransform;

		if (MapComponent->GetEngineTransform(Position, Rotation, EngineTransform))
		{
			bInternalHasChanged = false;
			bTransformHasChanged = true;
			GetOwner()->SetActorLocationAndRotation(EngineTransform.GetLocation(), EngineTransform.GetRotation(), false, nullptr,
													ETeleportType::ResetPhysics);
		}
	}
}

void UArcGISLocationComponent::UpdateGeoPositionAndRotation()
{
	if (MapComponent.IsValid() && MapComponent->HasSpatialReference())
	{
		auto EngineLocation = GetOwner()->GetActorLocation();
		auto GeographicCoordinates = MapComponent->EngineToGeographic(EngineLocation);

		if (!Position.IsValid())
		{
			return;
		}

		if (Position.SpatialReferenceWkid != GeographicCoordinates.SpatialReferenceWkid)
		{
			auto toSR = UArcGISSpatialReference::CreateArcGISSpatialReference(Position.SpatialReferenceWkid);
			auto geometry = UArcGISGeometryEngine::Project(GeographicCoordinates, toSR);
			if (geometry != nullptr)
			{
				GeographicCoordinates = static_cast<UArcGISPoint*>(geometry);
			}
		}

		Position = GeographicCoordinates;

		// Get a transform to go from the View ENU to a ENU based at the object location
		// This is required because the API rotation is stored relative to the object ENU
		auto ViewENUToObjectENU = MapComponent->GetENUAtLocationToViewENUTransform(EngineLocation).Inverse();

		// Get the rotation relative to the object ENU
		const auto GeographicQuaternion = ViewENUToObjectENU.GetRotation() * GetComponentRotation().Quaternion();

		const auto GeographicRotator = GeographicQuaternion.Rotator();

		// The Unreal euler angles need to be converted to the API convention
		Rotation.Pitch = GeographicRotator.Pitch + 90;
		Rotation.Heading = GeographicRotator.Yaw + 90;
		Rotation.Roll = -GeographicRotator.Roll;
	}
}
