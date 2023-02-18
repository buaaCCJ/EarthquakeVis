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

#include "ArcGISMutablePartCollection.generated.h"

class UArcGISSpatialReference;
class UArcGISMutablePart;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISMutablePartCollection;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// A collection object that can be changed containing parts for a geometry.
/// Each part is represented by a <see cref="Esri::GameEngine::Geometry::ArcGISMutablePart">ArcGISMutablePart</see>.
/// </summary>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISImmutablePartCollection">ArcGISImmutablePartCollection</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISMutablePartCollection :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePartCollection")
    /// <summary>
    /// Creates a mutable part collection with a specified spatial reference.
    /// </summary>
    /// <param name="spatialReference">A spatial reference object, can be null.</param>
    /// <since>1.0.0</since>
    static UArcGISMutablePartCollection* CreateArcGISMutablePartCollectionWithSpatialReference(UArcGISSpatialReference* spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePartCollection")
    /// <summary>
    /// Indicates if the mutable part collection contains no parts.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsEmpty();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePartCollection")
    /// <summary>
    /// The number of parts in the collection.
    /// </summary>
    /// <since>1.0.0</since>
    int64 GetSize();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePartCollection")
    /// <summary>
    /// The spatial reference for the mutable part collection.
    /// </summary>
    /// <remarks>
    /// If the collection does not have a spatial reference null is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetSpatialReference();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePartCollection")
    /// <summary>
    /// Add a new part to the end of the mutable part collection.
    /// </summary>
    /// <param name="mutablePart">The part to add</param>
    /// <returns>
    /// the index where the part was added. If an error occurred, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    int64 AddPart(UArcGISMutablePart* mutablePart);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePartCollection")
    /// <summary>
    /// Returns a part at the specified index in the collection.
    /// </summary>
    /// <param name="index">The position in the collection.</param>
    /// <returns>
    /// The part at the specified position in the collection.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISMutablePart* GetPart(int64 index) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePartCollection")
    /// <summary>
    /// Retrieves the position of the segment in the mutable part collection.
    /// The first segment that is equal to the supplied segment is returned.
    /// </summary>
    /// <param name="mutablePart">The part to find</param>
    /// <returns>
    /// The position of the segment in the collection, -1 otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    int64 IndexOf(UArcGISMutablePart* mutablePart) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePartCollection")
    /// <summary>
    /// Inserts a part into the mutable part collection at the specified part index.
    /// </summary>
    /// <remarks>
    /// The part index can be equal to the part count and this is equivalent to adding a part to the end of the collection.
    /// </remarks>
    /// <param name="index">Zero-based index of the part.</param>
    /// <param name="mutablePart">The part to insert.</param>
    /// <since>1.0.0</since>
    void InsertPart(int64 index, UArcGISMutablePart* mutablePart);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePartCollection")
    /// <summary>
    /// Remove all parts from the mutable part collection.
    /// </summary>
    /// <remarks>
    /// After calling this method the mutable part collection is empty.
    /// </remarks>
    /// <since>1.0.0</since>
    void RemoveAll();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePartCollection")
    /// <summary>
    /// Removes a part from the mutable part collection.
    /// </summary>
    /// <param name="index">Zero-based index of the part.</param>
    /// <since>1.0.0</since>
    void RemovePart(int64 index);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMutablePartCollection")
    /// <summary>
    /// Replace a part in the mutable part collection at the specified part index.
    /// </summary>
    /// <param name="index">Zero-based index of the part</param>
    /// <param name="mutablePart">Collection of segments representing the part.</param>
    /// <since>1.0.0</since>
    void SetPart(int64 index, UArcGISMutablePart* mutablePart);
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISMutablePartCollection> APIObject;
};