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

#include "ArcGISLayerCollection.generated.h"

class UArcGISLayer;

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace Base
{
class ArcGISLayer;
} // namespace Base
} // namespace Layers
} // namespace GameEngine

namespace Unreal
{
template<typename T> class ArcGISCollection;
} // namespace Unreal
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Defines a dynamic array that provides callbacks when ArcGISLayers are added or removed.
/// </summary>
/// <remarks>
/// The vector holds <see cref="Esri::GameEngine::Layers::Base::ArcGISLayer">ArcGISLayer</see> objects.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISLayerCollection :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Creates a vector. This allocates memory that must be deleted.
    /// </summary>
    /// <since>1.0.0</since>
    static UArcGISLayerCollection* CreateArcGISLayerCollection();
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
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
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Add a value to the vector.
    /// </summary>
    /// <param name="value">The value that is to be added.</param>
    /// <returns>
    /// The position of the value. Max value of size_t if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    int64 Add(UArcGISLayer* value);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Appends a vector to a vector.
    /// </summary>
    /// <param name="vector2">The value that is to be added.</param>
    /// <returns>
    /// The new size of vector_1. Max value of size_t if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    int64 AddArray(UArcGISLayerCollection* vector2);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Get a value at a specific position.
    /// </summary>
    /// <remarks>
    /// Retrieves the value at the specified position.
    /// </remarks>
    /// <param name="position">The position which you want to get the value.</param>
    /// <returns>
    /// The value, <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISLayer* At(int64 position) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
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
    bool Contains(UArcGISLayer* value) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Returns true if the two vectors are equal, false otherwise.
    /// </summary>
    /// <param name="vector2">The second vector.</param>
    /// <returns>
    /// Returns true if the two vectors are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(UArcGISLayerCollection* vector2) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Get the first value in the vector.
    /// </summary>
    /// <returns>
    /// The value, <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISLayer* First() const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Retrieves the position of the given value in the vector.
    /// </summary>
    /// <param name="value">The value you want to find.</param>
    /// <returns>
    /// The position of the value in the vector, Max value of size_t otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    int64 IndexOf(UArcGISLayer* value) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Insert a value at the specified position in the vector.
    /// </summary>
    /// <remarks>
    /// Insert a value at a specified position to the vector.
    /// </remarks>
    /// <param name="position">The position which you want to insert the value.</param>
    /// <param name="value">The value that is to be added.</param>
    /// <since>1.0.0</since>
    void Insert(int64 position, UArcGISLayer* value);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
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
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Get the last value in the vector.
    /// </summary>
    /// <returns>
    /// The value, <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISLayer* Last() const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Move a value from the current position to a new position in the string vector.
    /// </summary>
    /// <remarks>
    /// Move a value from the current position to a new position in the vector.
    /// </remarks>
    /// <param name="oldPosition">The current position of the value.</param>
    /// <param name="newPosition">The position which you want to move the value to.</param>
    /// <since>1.0.0</since>
    void Move(int64 oldPosition, int64 newPosition);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Returns a value indicating a bad position within the vector.
    /// </summary>
    /// <returns>
    /// A size_t.
    /// </returns>
    /// <since>1.0.0</since>
    static int64 Npos();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Remove a value at a specific position in the vector.
    /// </summary>
    /// <param name="position">The position which you want to remove the value.</param>
    /// <since>1.0.0</since>
    void Remove(int64 position);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISLayerCollection")
    /// <summary>
    /// Remove all values from the vector.
    /// </summary>
    /// <since>1.0.0</since>
    void RemoveAll();
    #pragma endregion Methods

public:
    TSharedPtr<Esri::Unreal::ArcGISCollection<Esri::GameEngine::Layers::Base::ArcGISLayer>> APIObject;
};