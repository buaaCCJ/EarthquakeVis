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

#include "ArcGISVectorTileSourceInfoImmutableCollection.generated.h"

class UArcGISVectorTileSourceInfo;

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace VectorTile
{
class ArcGISVectorTileSourceInfo;
} // namespace VectorTile
} // namespace Layers
} // namespace GameEngine

namespace Unreal
{
template<typename T> class ArcGISImmutableCollection;
} // namespace Unreal
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Defines an immutable collection of <see cref="Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo">ArcGISVectorTileSourceInfo</see>.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISVectorTileSourceInfoImmutableCollection :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfoImmutableCollection")
    /// <summary>
    /// Determines the number of values in the vector.
    /// </summary>
    /// <remarks>
    /// The number of values in the vector. If an error occurs a 0 will be returned.
    /// </remarks>
    /// <since>1.0.0</since>
    int64 GetSize();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfoImmutableCollection")
    /// <summary>
    /// Get a value at a specific position.
    /// </summary>
    /// <remarks>
    /// Retrieves the value at the specified position.
    /// </remarks>
    /// <param name="position">The position which you want to get the value.</param>
    /// <returns>
    /// The value, <see cref="Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo">ArcGISVectorTileSourceInfo</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISVectorTileSourceInfo* At(int64 position) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfoImmutableCollection")
    /// <summary>
    /// Does the vector contain the given value.
    /// </summary>
    /// <remarks>
    /// Does the vector contain a specific value.
    /// </remarks>
    /// <param name="value">The value you want to find.</param>
    /// <returns>
    /// True if the value is in the vector otherwise false.
    /// </returns>
    /// <since>1.0.0</since>
    bool Contains(UArcGISVectorTileSourceInfo* value) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfoImmutableCollection")
    /// <summary>
    /// Returns true if the two vectors are equal, false otherwise.
    /// </summary>
    /// <param name="vector2">The second vector.</param>
    /// <returns>
    /// Returns true if the two vectors are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(UArcGISVectorTileSourceInfoImmutableCollection* vector2) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfoImmutableCollection")
    /// <summary>
    /// Get the first value in the vector.
    /// </summary>
    /// <returns>
    /// The value, <see cref="Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo">ArcGISVectorTileSourceInfo</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISVectorTileSourceInfo* First() const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfoImmutableCollection")
    /// <summary>
    /// Retrieves the position of the given value in the vector.
    /// </summary>
    /// <param name="value">The value you want to find.</param>
    /// <returns>
    /// The position of the value in the vector, Max value of size_t otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    int64 IndexOf(UArcGISVectorTileSourceInfo* value) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfoImmutableCollection")
    /// <summary>
    /// Determines if there are any values in the vector.
    /// </summary>
    /// <remarks>
    /// Check if the vector object has any values in it.
    /// </remarks>
    /// <returns>
    /// true if the  vector object contains no values otherwise false. Will return true if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    bool IsEmpty() const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfoImmutableCollection")
    /// <summary>
    /// Get the last value in the vector.
    /// </summary>
    /// <returns>
    /// The value, <see cref="Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo">ArcGISVectorTileSourceInfo</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISVectorTileSourceInfo* Last() const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISVectorTileSourceInfoImmutableCollection")
    /// <summary>
    /// Returns a value indicating a bad position within the vector.
    /// </summary>
    /// <returns>
    /// A size_t.
    /// </returns>
    /// <since>1.0.0</since>
    static int64 Npos();
    #pragma endregion Methods

public:
    TSharedPtr<Esri::Unreal::ArcGISImmutableCollection<Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo>> APIObject;
};