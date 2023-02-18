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

#include "ArcGISImmutablePartCollection.generated.h"

class UArcGISSpatialReference;
class UArcGISImmutablePart;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISImmutablePartCollection;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Represents immutable collection of parts for a polygon or polyline geometry. Each part is a collection of segments.
/// </summary>
/// <remarks>
/// Polygons and polyline can have multiple disjoint parts.
/// Each part is represented by a <see cref="Esri::GameEngine::Geometry::ArcGISImmutablePart">ArcGISImmutablePart</see>.
/// A part is composed of segments representing the edge of the polygon or polyline.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISImmutablePartCollection :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISImmutablePartCollection")
    /// <summary>
    /// Indicates if the immutable part collection contains no parts.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsEmpty();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISImmutablePartCollection")
    /// <summary>
    /// The number of parts in the immutable part collection.
    /// </summary>
    /// <since>1.0.0</since>
    int64 GetSize();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISImmutablePartCollection")
    /// <summary>
    /// The spatial reference for the immutable part collection.
    /// </summary>
    /// <remarks>
    /// If the collection does not have a spatial reference null is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetSpatialReference();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISImmutablePartCollection")
    /// <summary>
    /// Returns a part at the specified index in the immutable part collection.
    /// A part is represented by a immutable collection of segments.
    /// </summary>
    /// <param name="index">Position to retrieve the part.</param>
    /// <returns>
    /// the immutable part at the specified part index.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISImmutablePart* GetPart(int64 index) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISImmutablePartCollection")
    /// <summary>
    /// Retrieves the position of the given part in the immutable part collection
    /// </summary>
    /// <param name="immutablePart">The part you want to find.</param>
    /// <returns>
    /// The position of the part in the collection, -1 otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    int64 IndexOf(UArcGISImmutablePart* immutablePart) const;
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISImmutablePartCollection> APIObject;
};