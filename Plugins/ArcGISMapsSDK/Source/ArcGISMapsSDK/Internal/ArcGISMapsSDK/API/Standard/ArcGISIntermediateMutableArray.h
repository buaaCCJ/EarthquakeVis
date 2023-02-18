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

#include "ArcGISMapsSDK/API/Standard/ArcGISMutableArrayElementAddedEvent.h"
#include "ArcGISMapsSDK/API/Standard/ArcGISMutableArrayElementRemovedEvent.h"

namespace Esri
{
namespace Unreal
{
template<typename T> class ArcGISList;
} // namespace Unreal

namespace Standard
{
class ArcGISElement;
enum class ArcGISElementType;

/// <summary>
/// Defines a dynamic array that provides callbacks when elements are added or removed.
/// </summary>
/// <remarks>
/// The vector holds <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> objects. Use <see cref="Esri::Standard::ArcGISIntermediateMutableArray.valueType">ArcGISIntermediateMutableArray.valueType</see> to determine what type of <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see>
/// objects are being stored in the vector. A <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> that has been retrieved from the vector can be converted
/// to its underlying type by calling (for example) int32_t int_value = RT_Element_getValueAsInt32(element_handle, error_handler);
/// 
/// There are a couple of performance optimizations to consider with the generic collection type:
/// 1.  The <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> object can be reused for multiple calls while adding/inserting/updating values within
/// the collection.  So you can instantiate one <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> and iteratively change its value and call
/// add/update/insert on the collection to modify the values of the collection.
/// 2.  If the overhead of creating these <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> does become too much for a specific value type, then
/// consider subclassing the collection type and provide "overloaded" methods that would accept that value type
/// directly.  This would eliminate the overhead of instantiating these <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> objects.
/// </remarks>
/// <since>1.0.0</since>
class ArcGISIntermediateMutableArray
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a vector. This allocates memory that must be deleted.
    /// </summary>
    /// <param name="valueType">The type of the values this vector holds.</param>
    /// <since>1.0.0</since>
    ArcGISIntermediateMutableArray(ArcGISElementType valueType);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// Determines the number of values in the vector.
    /// </summary>
    /// <remarks>
    /// The number of values in the vector. If an error occurs a 0 will be returned.
    /// </remarks>
    /// <since>1.0.0</since>
    size_t GetSize() const;
    
    /// <summary>
    /// The type of the values this vector holds.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISElementType GetValueType() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Appends a vector to a vector.
    /// </summary>
    /// <param name="vector2">A vector object that contains the values to append.</param>
    /// <returns>
    /// The new size of vector_1. Max value of size_t if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    size_t Add(const Unreal::ArcGISList<ArcGISElement>& vector2);
    
    /// <summary>
    /// Add a value to the vector.
    /// </summary>
    /// <param name="value">The value that is to be added.</param>
    /// <returns>
    /// The position of the value. Max value of size_t if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    size_t Add(const ArcGISElement& value);
    
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
    ArcGISElement At(size_t position) const;
    
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
    bool Contains(const ArcGISElement& value) const;
    
    /// <summary>
    /// Returns true if the two vectors are equal, false otherwise.
    /// </summary>
    /// <param name="vector2">The second vector.</param>
    /// <returns>
    /// Returns true if the two vectors are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(const Unreal::ArcGISList<ArcGISElement>& vector2) const;
    
    /// <summary>
    /// Get the first value in the vector.
    /// </summary>
    /// <returns>
    /// The value, <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISElement First() const;
    
    /// <summary>
    /// Retrieves the position of the given value in the vector.
    /// </summary>
    /// <param name="value">The value you want to find.</param>
    /// <returns>
    /// The position of the value in the vector, Max value of size_t otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    size_t IndexOf(const ArcGISElement& value) const;
    
    /// <summary>
    /// Insert a value at the specified position in the vector.
    /// </summary>
    /// <remarks>
    /// Insert a value at a specified position to the vector.
    /// </remarks>
    /// <param name="position">The position which you want to insert the value.</param>
    /// <param name="value">The value that is to be added.</param>
    /// <since>1.0.0</since>
    void Insert(size_t position, const ArcGISElement& value);
    
    /// <summary>
    /// Determines if there are any values in the vector.
    /// </summary>
    /// <remarks>
    /// Check if the vector object has any values in it.
    /// </remarks>
    /// <returns>
    /// true if the vector object contains no values otherwise false. Will return true if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    bool IsEmpty() const;
    
    /// <summary>
    /// Get the last value in the vector.
    /// </summary>
    /// <returns>
    /// The value, <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISElement Last() const;
    
    /// <summary>
    /// Move a value from the current position to a new position in the string vector.
    /// </summary>
    /// <remarks>
    /// Move a value from the current position to a new position in the vector.
    /// </remarks>
    /// <param name="oldPosition">The current position of the value.</param>
    /// <param name="newPosition">The position which you want to move the value to.</param>
    /// <since>1.0.0</since>
    void Move(size_t oldPosition, size_t newPosition);
    
    /// <summary>
    /// Returns a value indicating a bad position within the vector.
    /// </summary>
    /// <returns>
    /// A size_t.
    /// </returns>
    /// <since>1.0.0</since>
    static size_t Npos();
    
    /// <summary>
    /// Remove a value at a specific position in the vector.
    /// </summary>
    /// <param name="position">The position which you want to remove the value.</param>
    /// <since>1.0.0</since>
    void Remove(size_t position);
    
    /// <summary>
    /// Remove all values from the vector.
    /// </summary>
    /// <since>1.0.0</since>
    void RemoveAll();
    #pragma endregion Methods
    
    #pragma region Events
    /// <summary>
    /// Callback invoked when an element has been added to the vector.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISMutableArrayElementAddedEvent<ArcGISElement> GetElementAdded() const;
    void SetElementAdded(ArcGISMutableArrayElementAddedEvent<ArcGISElement> elementAdded);
    
    /// <summary>
    /// Callback invoked when an element has been removed from the vector.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISMutableArrayElementRemovedEvent<ArcGISElement> GetElementRemoved() const;
    void SetElementRemoved(ArcGISMutableArrayElementRemovedEvent<ArcGISElement> elementRemoved);
    #pragma endregion Events

public:
    #pragma region Special Members
    explicit ArcGISIntermediateMutableArray(void* handle);
    
    ArcGISIntermediateMutableArray(const ArcGISIntermediateMutableArray&) = delete;
    
    ArcGISIntermediateMutableArray(ArcGISIntermediateMutableArray&& other) noexcept;
    
    ArcGISIntermediateMutableArray() = default;
    
    ~ArcGISIntermediateMutableArray();
    
    ArcGISIntermediateMutableArray& operator=(const ArcGISIntermediateMutableArray&) = delete;
    
    ArcGISIntermediateMutableArray& operator=(ArcGISIntermediateMutableArray&& other) noexcept;
    
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
    ArcGISMutableArrayElementAddedEvent<ArcGISElement> m_elementAdded;
    ArcGISMutableArrayElementRemovedEvent<ArcGISElement> m_elementRemoved;
};
} // namespace Standard
} // namespace Esri