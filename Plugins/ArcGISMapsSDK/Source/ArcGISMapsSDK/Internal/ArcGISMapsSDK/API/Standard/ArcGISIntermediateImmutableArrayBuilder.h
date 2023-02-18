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
class ArcGISElement;
enum class ArcGISElementType;

/// <summary>
/// Use to create and populate <see cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</see> collections.
/// </summary>
/// <remarks>
/// The <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see> provides a mechanism for creating and populating <see cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</see> objects.
/// Because <see cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</see> objects cannot be created or populate directly (they are immutable
/// objects) the <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see> provides an efficient means to overcome this.
/// 
/// Use <see cref="Esri::Standard::ArcGISIntermediateImmutableArray.createBuilder">ArcGISIntermediateImmutableArray.createBuilder</see> to create a <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see>.
/// 
/// There are a couple of performance optimizations to consider when adding values to an <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see>:
/// 1. A single instance of a <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> object can be reused by setting its value prior to each call
/// to <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder.add">ArcGISIntermediateImmutableArrayBuilder.add</see>.
/// 2. If the overhead of creating these <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> is too much for a specific value type, consider
/// subclassing the <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see> and provide "overloaded" methods that would accept that value type
/// directly. This would eliminate the overhead of instantiating these <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> objects.
/// </remarks>
/// <seealso cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</seealso>
/// <seealso cref="Esri::Standard::ArcGISIntermediateMutableArray">ArcGISIntermediateMutableArray</seealso>
/// <since>1.0.0</since>
class ArcGISIntermediateImmutableArrayBuilder
{
public:
    #pragma region Properties
    /// <summary>
    /// The type of the values this <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see> holds.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISElementType GetValueType() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Add a value to the <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see>.
    /// </summary>
    /// <param name="value">The value that is to be added.</param>
    /// <since>1.0.0</since>
    void Add(const ArcGISElement& value);
    
    /// <summary>
    /// Creates a <see cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</see> containing the values added to this <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see>.
    /// </summary>
    /// <remarks>
    /// The order of the values in the returned <see cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</see> matches the order in which the
    /// values were added to this <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see>.
    /// 
    /// This call empties this <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see> of values, but leaves it in a valid
    /// (re-usable) state.
    /// </remarks>
    /// <returns>
    /// A <see cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</see> containing the values added to this <see cref="Esri::Standard::ArcGISIntermediateImmutableArrayBuilder">ArcGISIntermediateImmutableArrayBuilder</see>.
    /// </returns>
    /// <since>1.0.0</since>
    Unreal::ArcGISImmutableArray<ArcGISElement> MoveToArray();
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISIntermediateImmutableArrayBuilder(void* handle);
    
    ArcGISIntermediateImmutableArrayBuilder(const ArcGISIntermediateImmutableArrayBuilder&) = delete;
    
    ArcGISIntermediateImmutableArrayBuilder(ArcGISIntermediateImmutableArrayBuilder&& other) noexcept;
    
    ArcGISIntermediateImmutableArrayBuilder() = default;
    
    ~ArcGISIntermediateImmutableArrayBuilder();
    
    ArcGISIntermediateImmutableArrayBuilder& operator=(const ArcGISIntermediateImmutableArrayBuilder&) = delete;
    
    ArcGISIntermediateImmutableArrayBuilder& operator=(ArcGISIntermediateImmutableArrayBuilder&& other) noexcept;
    
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Standard
} // namespace Esri