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
template<typename T> class ArcGISImmutableCollection;
} // namespace Unreal

namespace GameEngine
{
namespace Layers
{
namespace VectorTile
{
class ArcGISVectorTileSourceInfo;

/// <summary>
/// Defines an immutable collection of <see cref="Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo">ArcGISVectorTileSourceInfo</see>.
/// </summary>
/// <since>1.0.0</since>
class ArcGISVectorTileSourceInfoImmutableCollection
{
public:
    #pragma region Properties
    /// <summary>
    /// Determines the number of values in the vector.
    /// </summary>
    /// <remarks>
    /// The number of values in the vector. If an error occurs a 0 will be returned.
    /// </remarks>
    /// <since>1.0.0</since>
    size_t GetSize() const;
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
    /// The value, <see cref="Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo">ArcGISVectorTileSourceInfo</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISVectorTileSourceInfo At(size_t position) const;
    
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
    bool Contains(const ArcGISVectorTileSourceInfo& value) const;
    
    /// <summary>
    /// Returns true if the two vectors are equal, false otherwise.
    /// </summary>
    /// <param name="vector2">The second vector.</param>
    /// <returns>
    /// Returns true if the two vectors are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(const Unreal::ArcGISImmutableCollection<ArcGISVectorTileSourceInfo>& vector2) const;
    
    /// <summary>
    /// Get the first value in the vector.
    /// </summary>
    /// <returns>
    /// The value, <see cref="Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo">ArcGISVectorTileSourceInfo</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISVectorTileSourceInfo First() const;
    
    /// <summary>
    /// Retrieves the position of the given value in the vector.
    /// </summary>
    /// <param name="value">The value you want to find.</param>
    /// <returns>
    /// The position of the value in the vector, Max value of size_t otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    size_t IndexOf(ArcGISVectorTileSourceInfo& value) const;
    
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
    
    /// <summary>
    /// Get the last value in the vector.
    /// </summary>
    /// <returns>
    /// The value, <see cref="Esri::GameEngine::Layers::VectorTile::ArcGISVectorTileSourceInfo">ArcGISVectorTileSourceInfo</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISVectorTileSourceInfo Last() const;
    
    /// <summary>
    /// Returns a value indicating a bad position within the vector.
    /// </summary>
    /// <returns>
    /// A size_t.
    /// </returns>
    /// <since>1.0.0</since>
    static size_t Npos();
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISVectorTileSourceInfoImmutableCollection(void* handle);
    ArcGISVectorTileSourceInfoImmutableCollection(const ArcGISVectorTileSourceInfoImmutableCollection&) = delete;
    ArcGISVectorTileSourceInfoImmutableCollection(ArcGISVectorTileSourceInfoImmutableCollection&& other) noexcept;
    ArcGISVectorTileSourceInfoImmutableCollection() = default;
    ~ArcGISVectorTileSourceInfoImmutableCollection();
    
    ArcGISVectorTileSourceInfoImmutableCollection& operator=(const ArcGISVectorTileSourceInfoImmutableCollection&) = delete;
    ArcGISVectorTileSourceInfoImmutableCollection& operator=(ArcGISVectorTileSourceInfoImmutableCollection&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace VectorTile
} // namespace Layers
} // namespace GameEngine
} // namespace Esri