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

#include "ArcGISMutablePointCollection.generated.h"

class UArcGISSpatialReference;
class UArcGISPoint;
class UArcGISImmutablePointCollection;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISMutablePointCollection;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// A collection object that can be changed containing points.
/// </summary>
/// <remarks>
/// Contains a collection of points that can be changed.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISImmutablePointCollection">ArcGISImmutablePointCollection</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISMutablePointCollection :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Creates a mutable point collection with a specified spatial reference.
    /// </summary>
    /// <param name="spatialReference">A spatial reference object, can be null.</param>
    /// <since>1.0.0</since>
    static UArcGISMutablePointCollection* CreateArcGISMutablePointCollectionWithSpatialReference(UArcGISSpatialReference* spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Indicates if the mutable point collection contains no points.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsEmpty();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// The number of points in the collection.
    /// </summary>
    /// <since>1.0.0</since>
    int64 GetSize();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// The spatial reference for the mutable point collection.
    /// </summary>
    /// <remarks>
    /// If the collection does not have a spatial reference null is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetSpatialReference();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Add a new point to the end of the mutable point collection by specifying the points x,y coordinates.
    /// </summary>
    /// <param name="x">The x-coordinate of the new point.</param>
    /// <param name="y">The y-coordinate of the new point</param>
    /// <returns>
    /// the point index where the point was added. If an error occurred, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    int64 AddPointXY(double x, double y);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Add a new point to the end of the mutable point collection by specifying the points x,y,z coordinates.
    /// </summary>
    /// <param name="x">The x-coordinate of the new point.</param>
    /// <param name="y">The y-coordinate of the new point.</param>
    /// <param name="z">The z coordinate of the new point.</param>
    /// <returns>
    /// the point index where the point was added. If an error occurred, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    int64 AddPointXYZ(double x, double y, double z);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Add a new point to the end of the mutable point collection.
    /// </summary>
    /// <param name="point">The point to add</param>
    /// <returns>
    /// the point index where the point was added. If an error occurred, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    int64 AddPoint(UArcGISPoint* point);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Add a new points to the end of the mutable point collection.
    /// </summary>
    /// <param name="points">The new points to add</param>
    /// <since>1.0.0</since>
    void AddPointsFromImmutable(UArcGISImmutablePointCollection* points);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Add a new points to the end of the mutable point collection.
    /// </summary>
    /// <param name="points">The new points to add</param>
    /// <since>1.0.0</since>
    void AddPoints(UArcGISMutablePointCollection* points);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Returns a point at the specified index in the collection.
    /// </summary>
    /// <param name="index">The position in the collection.</param>
    /// <returns>
    /// The point at the specified position in the collection.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISPoint* GetPoint(int64 index) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Retrieves the position of the point in the mutable point collection.
    /// The first point that is equal to the supplied point is returned.
    /// </summary>
    /// <param name="point">The point to find</param>
    /// <returns>
    /// The position of the point in the collection, -1 otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    int64 IndexOf(UArcGISPoint* point) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Inserts a point specified by its x,y coordinates into the mutable point collection at the specified point index.
    /// </summary>
    /// <remarks>
    /// The point index can be equal to the point count and this is equivalent to adding a point to the end of the collection.
    /// </remarks>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="x">The x-coordinate of the new point.</param>
    /// <param name="y">The y-coordinate of the new point</param>
    /// <since>1.0.0</since>
    void InsertPointXY(int64 pointIndex, double x, double y);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Inserts a point specified by its x,y,z coordinate into the mutable point collection at the specified point index.
    /// </summary>
    /// <remarks>
    /// The point index can be equal to the point count and this is equivalent to adding a point to the end of the collection.
    /// </remarks>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="x">The x-coordinate of the new point.</param>
    /// <param name="y">The y-coordinate of the new point</param>
    /// <param name="z">The z-coordinate of the new point</param>
    /// <since>1.0.0</since>
    void InsertPointXYZ(int64 pointIndex, double x, double y, double z);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Inserts a point into the mutable point collection at the specified point index.
    /// </summary>
    /// <remarks>
    /// The point index can be equal to the point count and this is equivalent to adding a point to the end of the collection.
    /// </remarks>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="point">The point to insert.</param>
    /// <since>1.0.0</since>
    void InsertPoint(int64 pointIndex, UArcGISPoint* point);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Remove all points from the mutable point collection.
    /// </summary>
    /// <remarks>
    /// After calling this method the mutable point collection is empty.
    /// </remarks>
    /// <since>1.0.0</since>
    void RemoveAll();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Removes a point from the mutable point collection.
    /// </summary>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <since>1.0.0</since>
    void RemovePoint(int64 pointIndex);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePointCollection")
    /// <summary>
    /// Replace a point in the mutable point collection at the specified point index.
    /// </summary>
    /// <param name="pointIndex">Zero-based index of the point.</param>
    /// <param name="point">The point.</param>
    /// <since>1.0.0</since>
    void SetPoint(int64 pointIndex, UArcGISPoint* point);
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISMutablePointCollection> APIObject;
};