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

namespace Esri
{
namespace Unreal
{
template<typename T> class ArcGISImmutableArray;
} // namespace Unreal

namespace Standard
{
enum class ArcGISArrayType;
class ArcGISElement;
enum class ArcGISElementType;
class ArcGISIntermediateImmutableArrayBuilder;

/// <summary>
/// Defines a immutable dynamic array.
/// </summary>
/// <remarks>
/// The array holds <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> objects. Use <see cref="Esri::Standard::ArcGISIntermediateImmutableArray.valueType">ArcGISIntermediateImmutableArray.valueType</see> to determine what type of <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see>
/// objects are being stored in the array. A <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> that has been retrieved from the array can be converted
/// to its underlying type by calling (for example) int32_t int_value = RT_Element_getValueAsInt32(element_handle, error_handler);
/// </remarks>
/// <since>1.0.0</since>
class ArcGISIntermediateImmutableArray
{
public:
    #pragma region Properties
    /// <summary>
    /// The type of the array.
    /// </summary>
    /// <remarks>
    /// The type of the array object.
    /// </remarks>
    /// <seealso cref="Esri::Standard::ArcGISArrayType">ArcGISArrayType</seealso>
    /// <since>1.0.0</since>
    ArcGISArrayType GetObjectType() const;
    
    /// <summary>
    /// Determines the number of values in the array.
    /// </summary>
    /// <remarks>
    /// The number of values in the array. If an error occurs a 0 will be returned.
    /// </remarks>
    /// <since>1.0.0</since>
    size_t GetSize() const;
    
    /// <summary>
    /// The type of the values this array holds.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISElementType GetValueType() const;
    #pragma endregion Properties
    
    #pragma region Methods
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
    /// Does the array contain the given value.
    /// </summary>
    /// <remarks>
    /// Does the array contain a specific value.
    /// </remarks>
    /// <param name="value">The value you want to find.</param>
    /// <returns>
    /// True if the value is in the array otherwise false.
    /// </returns>
    /// <since>1.0.0</since>
    bool Contains(const ArcGISElement& value) const;
    
    /// <summary>
    /// Creates a <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see>.
    /// </summary>
    /// <param name="valueType">The type of the values the returned <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see> holds.</param>
    /// <returns>
    /// A <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see>
    /// </returns>
    /// <seealso cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</seealso>
    /// <since>1.0.0</since>
    static ArcGISIntermediateImmutableArrayBuilder CreateBuilder(ArcGISElementType valueType);
    
    /// <summary>
    /// Returns true if the two arrays are equal, false otherwise.
    /// </summary>
    /// <param name="array2">The second array.</param>
    /// <returns>
    /// Returns true if the two arrays are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(const Unreal::ArcGISImmutableArray<ArcGISElement>& array2) const;
    
    /// <summary>
    /// Get the first value in the array.
    /// </summary>
    /// <returns>
    /// The value, <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISElement First() const;
    
    /// <summary>
    /// Retrieves the position of the given value in the array.
    /// </summary>
    /// <param name="value">The value you want to find.</param>
    /// <returns>
    /// The position of the value in the array, or the max value of size_t otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    size_t IndexOf(const ArcGISElement& value) const;
    
    /// <summary>
    /// Determines if there are any values in the array.
    /// </summary>
    /// <remarks>
    /// Check if the array object has any values in it.
    /// </remarks>
    /// <returns>
    /// true if the  array object contains no values otherwise false. Will return true if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    bool IsEmpty() const;
    
    /// <summary>
    /// Get the last value in the array.
    /// </summary>
    /// <returns>
    /// The value, <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISElement Last() const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISIntermediateImmutableArray(void* handle);
    
    ArcGISIntermediateImmutableArray(const ArcGISIntermediateImmutableArray&) = delete;
    
    ArcGISIntermediateImmutableArray(ArcGISIntermediateImmutableArray&& other) noexcept;
    
    ArcGISIntermediateImmutableArray() = default;
    
    ~ArcGISIntermediateImmutableArray();
    
    ArcGISIntermediateImmutableArray& operator=(const ArcGISIntermediateImmutableArray&) = delete;
    
    ArcGISIntermediateImmutableArray& operator=(ArcGISIntermediateImmutableArray&& other) noexcept;
    
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Standard
} // namespace Esri