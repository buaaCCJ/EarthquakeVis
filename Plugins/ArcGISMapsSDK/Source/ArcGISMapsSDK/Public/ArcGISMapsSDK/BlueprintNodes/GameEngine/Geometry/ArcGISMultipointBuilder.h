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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryBuilder.h"

#include "ArcGISMultipointBuilder.generated.h"

class UArcGISMutablePointCollection;
class UArcGISMultipoint;
class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISMultipointBuilder;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// The multipoint builder object is used to create a multipoint.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISMultipointBuilder :
    public UArcGISGeometryBuilder
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMultipointBuilder")
    /// <summary>
    /// Creates a multipoint builder from a multipoint.
    /// </summary>
    /// <param name="multipoint">A multipoint object.</param>
    /// <since>1.0.0</since>
    static UArcGISMultipointBuilder* CreateArcGISMultipointBuilderFromMultipoint(UArcGISMultipoint* multipoint);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMultipointBuilder")
    /// <summary>
    /// Creates a multipoint builder.
    /// </summary>
    /// <param name="spatialReference">The builder's spatial reference.</param>
    /// <since>1.0.0</since>
    static UArcGISMultipointBuilder* CreateArcGISMultipointBuilderFromSpatialReference(UArcGISSpatialReference* spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMultipointBuilder")
    /// <summary>
    /// A mutable collection of points.
    /// </summary>
    /// <remarks>
    /// Use this collection to add points to or remove points from the builder.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISMutablePointCollection* GetPoints();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMultipointBuilder")
    /// <summary>
    /// A mutable collection of points.
    /// </summary>
    /// <remarks>
    /// Use this collection to add points to or remove points from the builder.
    /// </remarks>
    /// <since>1.0.0</since>
    void SetPoints(UArcGISMutablePointCollection* points);
    #pragma endregion Properties
};