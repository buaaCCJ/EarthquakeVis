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
#include "ArcGISMapsSDKEditor/MapCreator/CustomDetails/ArcGISMapCreatorCameraToolDetails.h"

#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#if WITH_EDITOR
#include "EditorViewportClient.h"
#endif
#include "GameFramework/DefaultPawn.h"
#include "IPropertyUtilities.h"
#include "Widgets/Input/SButton.h"

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryEngine.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Location/ArcGISRotation.h"
#include "ArcGISMapsSDK/Components/ArcGISCameraComponent.h"
#include "ArcGISMapsSDK/Components/ArcGISLocationComponent.h"
#include "ArcGISMapsSDK/Utils/GeoCoord/GeoPosition.h"

#include "ArcGISMapsSDKEditor/MapCreator/ArcGISMapCreatorUtilities.h"

using namespace MapCreatorUtilities;

namespace
{
bool IsPawnValid(APawn* pawn)
{
	return !pawn || !pawn->FindComponentByClass<UArcGISCameraComponent>() || !pawn->FindComponentByClass<UArcGISLocationComponent>();
}

void SetPawnCamera(APawn* pawn)
{
	auto cameraComponent = pawn->FindComponentByClass<UArcGISCameraComponent>();

	if (!cameraComponent)
	{
		cameraComponent = NewObject<UArcGISCameraComponent>(pawn, FName("ArcGISCamera"), RF_Transactional);

		cameraComponent->AttachToComponent(pawn->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);

		pawn->AddInstanceComponent(cameraComponent);

		cameraComponent->RegisterComponent();
	}
}

void SetPawnLocation(APawn* pawn, const FGeoPosition& position, UArcGISRotation* rotation)
{
	auto locationComponent = pawn->FindComponentByClass<UArcGISLocationComponent>();

	if (!locationComponent)
	{
		locationComponent = NewObject<UArcGISLocationComponent>(pawn, FName("ArcGISLocation"), RF_Transactional);

		locationComponent->AttachToComponent(pawn->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);

		pawn->AddInstanceComponent(locationComponent);

		locationComponent->RegisterComponent();
	}

	locationComponent->SetPosition(static_cast<UArcGISPoint*>(position));
	locationComponent->SetRotation(rotation);
}
} // namespace

UArcGISPoint* ProjectToSpatialReference(UArcGISPoint* position, UArcGISSpatialReference* toSpatialRef)
{
	if (position->GetSpatialReference()->Equals(toSpatialRef))
	{
		return position;
	}

	auto projected = UArcGISGeometryEngine::Project(position, toSpatialRef);

	if (projected == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ProjectToSpatialReference EXCEPTION THROWN: %d could not be projected to %d"),
			   position->GetSpatialReference()->GetWKID(), toSpatialRef->GetWKID());
		return nullptr;
	}

	auto projectedPoint = static_cast<UArcGISPoint*>(projected);
	return projectedPoint;
}

TSharedRef<IDetailCustomization> FArcGISMapCreatorCameraToolDetails::MakeInstance()
{
	return MakeShared<FArcGISMapCreatorCameraToolDetails>();
}

void FArcGISMapCreatorCameraToolDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TArray<TWeakObjectPtr<UObject>> object;
	DetailBuilder.GetObjectsBeingCustomized(object);
	TObjectPtr<UArcGISMapCreatorCameraToolProperties> properties = Cast<UArcGISMapCreatorCameraToolProperties>(object[0]);

	CreateAlignButton(DetailBuilder, properties);
	CreateCameraButton(DetailBuilder, properties);
}

void FArcGISMapCreatorCameraToolDetails::CreateAlignButton(IDetailLayoutBuilder& detailBuilder,
														   TObjectPtr<UArcGISMapCreatorCameraToolProperties> properties)
{
	constexpr char camCategoryName[] = "Camera";
	auto& createCameraButtonCategory = detailBuilder.EditCategory(camCategoryName);

	// clang-format off
	createCameraButtonCategory.AddCustomRow(FText::FromString(camCategoryName))
	.NameContent()
	[
		SNew(STextBlock)
		.Text(FText::FromString("Editor Mode View"))
		.Justification(ETextJustify::Center)
		.Margin(FMargin(0, 2, 0, 0))
		.Font(detailBuilder.GetDetailFont())
	]
	.ValueContent()
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.FillWidth(0.45f)
		.HAlign(EHorizontalAlignment::HAlign_Fill)
		[
			SNew(SButton)
			.Content()
			[
				SNew(STextBlock)
				.Text(FText::FromString("Align with View"))
				.Justification(ETextJustify::Center)
				.Margin(FMargin(0, 2, 0, 0))
				.Font(detailBuilder.GetDetailFont())
			]
			.OnClicked(this, &FArcGISMapCreatorCameraToolDetails::AlignView, properties, detailBuilder.GetPropertyUtilities())
		]
	];
	// clang-format on

	auto positionProp = detailBuilder.GetProperty("CameraPosition");
	detailBuilder.HideProperty(GET_MEMBER_NAME_CHECKED(UArcGISMapCreatorCameraToolProperties, CameraPosition));
	detailBuilder.AddPropertyToCategory(positionProp);

	auto rotationProp = detailBuilder.GetProperty("CameraRotation");
	detailBuilder.HideProperty(GET_MEMBER_NAME_CHECKED(UArcGISMapCreatorCameraToolProperties, CameraRotation));
	detailBuilder.AddPropertyToCategory(rotationProp);
}

void FArcGISMapCreatorCameraToolDetails::CreateCameraButton(IDetailLayoutBuilder& detailBuilder,
															TObjectPtr<UArcGISMapCreatorCameraToolProperties> properties)
{
	constexpr char camCategoryName[] = "Camera";
	auto& createCameraButtonCategory = detailBuilder.EditCategory(camCategoryName);
	auto buttonColor = FLinearColor(0.0f, 5.0f, 20.0f);

	auto world = GEditor->GetEditorWorldContext().World();
	auto pawn = Cast<APawn>(UGameplayStatics::GetActorOfClass(world, APawn::StaticClass()));

	auto isCreateEnabled = IsPawnValid(pawn);

	if (!isCreateEnabled)
	{
		buttonColor = FLinearColor::Gray;
	}

	// clang-format off
	createCameraButtonCategory.AddCustomRow(FText::FromString(camCategoryName))
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.FillWidth(1)
		.HAlign(EHorizontalAlignment::HAlign_Fill)
		[
			SNew(SSpacer)
		]
		+ SHorizontalBox::Slot()
		.FillWidth(0.5f)
		.HAlign(EHorizontalAlignment::HAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.HAlign(EHorizontalAlignment::HAlign_Fill)
			[
				SNew(SButton)
				.ButtonColorAndOpacity(buttonColor)
				.Content()
				[
					SNew(STextBlock)
					.Text(FText::FromString("Create"))
					.Justification(ETextJustify::Center)
					.Margin(FMargin(0, 2, 0, 0))
				]
				.OnClicked(this, &FArcGISMapCreatorCameraToolDetails::CreateCamera, properties, detailBuilder.GetPropertyUtilities())
				.IsEnabled(isCreateEnabled)
			]
		]
	];
	// clang-format on
}

FReply FArcGISMapCreatorCameraToolDetails::AlignView(TObjectPtr<UArcGISMapCreatorCameraToolProperties> properties,
													 TSharedRef<IPropertyUtilities> utilities)
{
#if WITH_EDITOR
	auto world = GEditor->GetEditorWorldContext().World();
	auto pawn = Cast<APawn>(UGameplayStatics::GetActorOfClass(world, APawn::StaticClass()));

	if (!pawn)
	{
		return FReply::Handled();
	}

	FVector Position;
	FRotator Rotation;

	if (world->WorldType == EWorldType::Editor)
	{
		if (auto activeViewport = GEditor->GetActiveViewport())
		{
			if (auto editorViewClient = static_cast<FEditorViewportClient*>(activeViewport->GetClient()))
			{
				Position = editorViewClient->GetViewLocation();
				Rotation = editorViewClient->GetViewRotation();

				// UE5 uses Rotator(0, 90, 0) as a base when using a orbit camera. We have to transform Yaw to have the same result.
				if (editorViewClient->bUsingOrbitCamera)
				{
					Rotation.Yaw = 90 - Rotation.Yaw;
				}
			}
		}
	}
	else
	{
		return FReply::Handled();
	}

	auto MapComponent = MapComponentManager::GetMapComponent();

	auto GeographicCoordinates = MapComponent->EngineToGeographic(Position);

	if (!GeographicCoordinates.IsValid())
	{
		return FReply::Handled();
	}

	// Get a transform to go from the View ENU to a ENU based at the camera location
	// This is required because the API expects the rotation to be relative to the camera ENU
	const auto ViewENUToCameraENU = MapComponent->GetENUAtLocationToViewENUTransform(Position).Inverse();

	// Get the rotation relative to the camera ENU
	const auto NewRotation = ViewENUToCameraENU.GetRotation() * Rotation.Quaternion();

	// Note that ENU and Unreal cameras are both left handed, which permits this direct calculation of the rotator without having to transform axis.
	const auto Rotator = NewRotation.Rotator();

	auto rotation = UArcGISRotation::CreateArcGISRotation(Rotator.Pitch + 90, -Rotator.Roll, Rotator.Yaw + 90);

	SetPawnLocation(pawn, GeographicCoordinates, rotation);

	const auto originalPoint = (UArcGISPoint*)properties->CameraPosition;
	const auto originalSpatialReference = originalPoint->GetSpatialReference();
	auto updatedPosition = ProjectToSpatialReference(GeographicCoordinates, originalSpatialReference);

	if (updatedPosition != nullptr)
	{
		properties->CameraPosition = updatedPosition;
	}

	properties->CameraRotation.CameraHeading = Rotator.Yaw + 90;
	properties->CameraRotation.CameraPitch = Rotator.Pitch + 90;
	properties->CameraRotation.CameraRoll = -Rotator.Roll;

	utilities->ForceRefresh();
#endif

	return FReply::Handled();
}

FReply FArcGISMapCreatorCameraToolDetails::CreateCamera(TObjectPtr<UArcGISMapCreatorCameraToolProperties> properties,
														TSharedRef<IPropertyUtilities> utilities)
{
	auto world = GEditor->GetEditorWorldContext().World();
	auto pawn = Cast<APawn>(UGameplayStatics::GetActorOfClass(world, APawn::StaticClass()));

	if (!pawn)
	{
		// Create sample pawn and start at it at the origin location
		pawn = world->SpawnActor<ADefaultPawn>();

		pawn->AutoPossessPlayer = EAutoReceiveInput::Player0;
	}

	auto rotation = UArcGISRotation::CreateArcGISRotation(properties->CameraRotation.CameraPitch, properties->CameraRotation.CameraRoll,
														  properties->CameraRotation.CameraHeading);

	SetPawnCamera(pawn);
	SetPawnLocation(pawn, properties->CameraPosition, rotation);

	utilities->ForceRefresh();

	return FReply::Handled();
}
