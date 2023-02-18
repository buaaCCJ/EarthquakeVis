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

#include "ArcGISImmutablePointCollection.generated.h"

class UArcGISSpatialReference;
class UArcGISPoint;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISImmutablePointCollection;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Represents an immutable collection of points.
/// </summary>
/// <remarks>
/// This collection is used to represent the content of a <see cref="Esri::GameEngine::Geometry::ArcGISMultipoint">ArcGISMultipoint</see> geometry.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISImmutablePointCollection :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISImmutablePointCollection")
    /// <summary>
    /// Indicates if the immutable point collection contains no points.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsEmpty();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISImmutablePointCollection")
    /// <summary>
    /// The number of points in the collection.
    /// </summary>
    /// <since>1.0.0</since>
    int64 GetSize();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISImmutablePointCollection")
    /// <summary>
    /// The spatial reference for the immutable point collection.
    /// </summary>
    /// <remarks>
    /// If the collection does not have a spatial reference null is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetSpatialReference();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISImmutablePointCollection")
    /// <summary>
    /// Returns a point at the specified index in the collection.
    /// </summary>
    /// <param name="index">The position in the collection.</param>
    /// <returns>
    /// The point at the specified position in the collection.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISPoint* GetPoint(int64 index) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISImmutablePointCollection")
    /// <summary>
    /// Retrieves the position of the point in the immutable point collection.
    /// The first point that is equal to the supplied point is returned.
    /// </summary>
    /// <param name="point">The point to find</param>
    /// <returns>
    /// The position of the point in the collection, -1 otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    int64 IndexOf(UArcGISPoint* point) const;
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISImmutablePointCollection> APIObject;
};