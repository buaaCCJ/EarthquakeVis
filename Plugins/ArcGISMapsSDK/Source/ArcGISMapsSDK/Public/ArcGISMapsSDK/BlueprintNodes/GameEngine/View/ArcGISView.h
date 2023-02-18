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
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/ArcGISGameEngineType.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/MapView/ArcGISGlobeModel.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/View/ArcGISViewOptions.h"

#include "ArcGISView.generated.h"

class UArcGISCamera;
class UArcGISMap;
class UArcGISSpatialReference;
class UArcGISViewState;
class UArcGISElevationSourceViewState;
class UArcGISLayerViewState;
class UArcGISPoint;
class UArcGISElevationSource;
class UArcGISLayer;

namespace Esri
{
namespace GameEngine
{
namespace View
{
class ArcGISView;
} // namespace View
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// A view for interaction with geographic content from an <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISView :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// Create a new <see cref="Esri::GameEngine::View::ArcGISView">ArcGISView</see>.
    /// </summary>
    /// <param name="gameEngineType">Specifies the client game engine type</param>
    /// <param name="globeModel">Specifies the model used to represent a 3D globe</param>
    /// <since>1.0.0</since>
    static UArcGISView* CreateArcGISView(EArcGISGameEngineType::Type gameEngineType, EArcGISGlobeModel::Type globeModel);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// The current camera
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISCamera* GetCamera();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// The current camera
    /// </summary>
    /// <since>1.0.0</since>
    void SetCamera(UArcGISCamera* camera);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// The current map document.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISMap* GetMap();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// The current map document.
    /// </summary>
    /// <since>1.0.0</since>
    void SetMap(UArcGISMap* map);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// The current View Spatial Reference.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetSpatialReference();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// The current view options for the <see cref="Esri::GameEngine::View::ArcGISView">ArcGISView</see>.
    /// </summary>
    /// <since>1.0.0</since>
    FArcGISViewOptions GetViewOptions();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// The current view options for the <see cref="Esri::GameEngine::View::ArcGISView">ArcGISView</see>.
    /// </summary>
    /// <since>1.0.0</since>
    void SetViewOptions(FArcGISViewOptions viewOptions);
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// Transforms a geographic coordinate in a GCS or PCS to game engine world cartesian space.
    /// If the view has no spatial reference the returned coordinate will have NaN values.
    /// </summary>
    /// <remarks>
    /// The geographicCoordinate.spatialReference does not have to match the view spatial reference (SR),
    /// but the coordinate will be internally reprojected to the view SR. Depending on the
    /// SR of geographicCoordinate, the result may be inaccurate, or the reprojection may fail and return
    /// NaN values, so specifying geographicCoordinate in the view SR is preferred.
    /// </remarks>
    /// <param name="geographicCoordinate">The geographic position in a GCS or PCS</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Math::ArcGISVector3">ArcGISVector3</see>.
    /// </returns>
    /// <since>1.0.0</since>
    FVector GeographicToWorld(UArcGISPoint* geographicCoordinate) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// Retrieve the view's view state.
    /// </summary>
    /// <returns>
    /// A <see cref="Esri::GameEngine::View::State::ArcGISViewState">ArcGISViewState</see>.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISViewState* GetViewViewState() const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// Retrieve the elevation source's view state.
    /// </summary>
    /// <param name="elevation">A elevation object to get the view state for.</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewState">ArcGISElevationSourceViewState</see>.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISElevationSourceViewState* GetElevationSourceViewState(UArcGISElevationSource* elevation) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// Retrieve the layer's view state.
    /// </summary>
    /// <param name="layer">A layer object to get the view state for.</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::View::State::ArcGISLayerViewState">ArcGISLayerViewState</see>.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISLayerViewState* GetLayerViewState(UArcGISLayer* layer) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// Handle a platform low memory event
    /// </summary>
    /// <since>1.0.0</since>
    void HandleLowMemoryWarning();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// Sets the quotas for system and video memory that can be used by the <see cref="Esri::GameEngine::View::ArcGISView">ArcGISView</see>
    /// </summary>
    /// <remarks>
    /// If provided video memory quota is < 0 on mobile devices, a shared memory model will be assumed.
    /// </remarks>
    /// <param name="systemMemory">The system memory quota in MiB</param>
    /// <param name="videoMemory">The video memory quota in MiB</param>
    /// <since>1.0.0</since>
    void SetMemoryQuotas(int64 systemMemory, int64 videoMemory);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// Sets the viewport size and field of view. 
    /// Either field of view angle can be set to 0 to indicate "unset".
    /// For example, if verticalFieldOfViewDegrees is 0.0, but horizontalFieldOfViewDegrees is greater than zero, then the viewport vertical field
    /// of view will be set to the appropriate value given the horizontal FOV and distortion factor. And vice versa.
    /// </summary>
    /// <param name="viewportWidthPixels">used in visible tile calculation, on the basis that DPI is 96.</param>
    /// <param name="viewportHeightPixels">used in visible tile calculation, on the basis that DPI is 96.</param>
    /// <param name="horizontalFieldOfViewDegrees">A value in degrees. The valid range is 0 to 120</param>
    /// <param name="verticalFieldOfViewDegrees">A value in degrees. The valid range is 0 to 120</param>
    /// <param name="verticalDistortionFactor">Determines how much the vertical field of view is distorted. A distortion factor of 1.0 is default. A distortion factor less than 1.0 will cause the visuals to be stretched taller in comparison to their width. A distortion factor greater than 1.0 will cause the visuals to be shrunk shorter in comparison to their width.</param>
    /// <since>1.0.0</since>
    void SetViewportProperties(int32 viewportWidthPixels, int32 viewportHeightPixels, float horizontalFieldOfViewDegrees, float verticalFieldOfViewDegrees, float verticalDistortionFactor);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISView")
    /// <summary>
    /// Transforms a world coordinate to a geographic coordinate in the spatial reference of the view.
    /// If the view has no spatial reference the returned coordinate will have NaN values.
    /// </summary>
    /// <param name="worldCoordinate">The game engine world coordinate</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see>.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISPoint* WorldToGeographic(FVector worldCoordinate) const;
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::View::ArcGISView> APIObject;
};