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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Elevation/Base/ArcGISElevationSourceType.h"

#include "ArcGISElevationSource.generated.h"

class UArcGISLoadable;
class UArcGISExtentRectangle;
class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Elevation
{
namespace Base
{
class ArcGISElevationSource;
} // namespace Base
} // namespace Elevation
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Abstract base class for all ElevationSources
/// </summary>
/// <remarks>
/// A base class of implementations of elevation sources.  To use an elevation source you create an instance of a 
/// derived class and set it in to a <see cref="Esri::GameEngine::Map::ArcGISMapElevation">ArcGISMapElevation</see> in the <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>. The combination of elevation sources within the 
/// <see cref="Esri::GameEngine::Map::ArcGISMapElevation">ArcGISMapElevation</see> generate a rendering surface on which data can be draped or offset from.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISElevationSource :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISElevationSource")
    /// <summary>
    /// Creates a new elevation source.
    /// </summary>
    /// <remarks>
    /// Creates a new elevation source.
    /// </remarks>
    /// <param name="source">Elevation source</param>
    /// <param name="type">ArcGISElevationSource type definition.</param>
    /// <param name="APIKey">API Key used to load data.</param>
    /// <since>1.0.0</since>
    static UArcGISElevationSource* CreateArcGISElevationSource(FString source, EArcGISElevationSourceType::Type type, FString APIKey);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISElevationSource")
    /// <summary>
    /// API Key will be sended on loading process to match the new credit system.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetAPIKey();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISElevationSource")
    /// <summary>
    /// The full extent of this ArcGISElevationSource, which is the extent where all ArcGISElevationSource data is contained.
    /// </summary>
    /// <remarks>
    /// You can use this to zoom
    /// to all of the data contained in this ArcGISElevationSource.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISExtentRectangle* GetExtent();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISElevationSource")
    /// <summary>
    /// Define if this elevation source is enabled or not.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsEnabled();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISElevationSource")
    /// <summary>
    /// Define if this elevation source is enabled or not.
    /// </summary>
    /// <since>1.0.0</since>
    void SetIsEnabled(bool isEnabled);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISElevationSource")
    /// <summary>
    /// Identifier for elevation source
    /// </summary>
    /// <since>1.0.0</since>
    FString GetName();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISElevationSource")
    /// <summary>
    /// Identifier for elevation source
    /// </summary>
    /// <since>1.0.0</since>
    void SetName(FString name);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISElevationSource")
    /// <summary>
    /// Source property will be a read only, it will be setup on the constructor
    /// </summary>
    /// <since>1.0.0</since>
    FString GetSource();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISElevationSource")
    /// <summary>
    /// The spatial reference of the elevation source.
    /// </summary>
    /// <remarks>
    /// <see cref="Esri::GameEngine::Elevation::ArcGISImageElevationSource">ArcGISImageElevationSource</see> <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> must match the <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> of the <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>.
    /// <see cref="Esri::GameEngine::Elevation::ArcGISImageElevationSource">ArcGISImageElevationSource</see> tiling scheme must be compatible with the tiling scheme of the <see cref="Esri::GameEngine::Map::ArcGISMap">ArcGISMap</see>.
    /// If any of the above constraints are violated, an <see cref="Esri::GameEngine::View::State::ArcGISElevationSourceViewState">ArcGISElevationSourceViewState</see> error is generated.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetSpatialReference();
    #pragma endregion Properties

public:
    TSharedPtr<Esri::GameEngine::Elevation::Base::ArcGISElevationSource> APIObject;
};