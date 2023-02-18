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
namespace GameEngine
{
namespace Geometry
{
class ArcGISMutablePart;
class ArcGISSpatialReference;

/// <summary>
/// A collection object that can be changed containing parts for a geometry.
/// Each part is represented by a <see cref="Esri::GameEngine::Geometry::ArcGISMutablePart">ArcGISMutablePart</see>.
/// </summary>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISImmutablePartCollection">ArcGISImmutablePartCollection</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISMutablePartCollection
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a mutable part collection with a specified spatial reference.
    /// </summary>
    /// <param name="spatialReference">A spatial reference object, can be null.</param>
    /// <since>1.0.0</since>
    ArcGISMutablePartCollection(const ArcGISSpatialReference& spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// Indicates if the mutable part collection contains no parts.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsEmpty() const;
    
    /// <summary>
    /// The number of parts in the collection.
    /// </summary>
    /// <since>1.0.0</since>
    size_t GetSize() const;
    
    /// <summary>
    /// The spatial reference for the mutable part collection.
    /// </summary>
    /// <remarks>
    /// If the collection does not have a spatial reference null is returned.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISSpatialReference GetSpatialReference() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Add a new part to the end of the mutable part collection.
    /// </summary>
    /// <param name="mutablePart">The part to add</param>
    /// <returns>
    /// the index where the part was added. If an error occurred, then -1 is returned.
    /// </returns>
    /// <since>1.0.0</since>
    size_t AddPart(const ArcGISMutablePart& mutablePart);
    
    /// <summary>
    /// Returns a part at the specified index in the collection.
    /// </summary>
    /// <param name="index">The position in the collection.</param>
    /// <returns>
    /// The part at the specified position in the collection.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISMutablePart GetPart(size_t index) const;
    
    /// <summary>
    /// Retrieves the position of the segment in the mutable part collection.
    /// The first segment that is equal to the supplied segment is returned.
    /// </summary>
    /// <param name="mutablePart">The part to find</param>
    /// <returns>
    /// The position of the segment in the collection, -1 otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    size_t IndexOf(const ArcGISMutablePart& mutablePart) const;
    
    /// <summary>
    /// Inserts a part into the mutable part collection at the specified part index.
    /// </summary>
    /// <remarks>
    /// The part index can be equal to the part count and this is equivalent to adding a part to the end of the collection.
    /// </remarks>
    /// <param name="index">Zero-based index of the part.</param>
    /// <param name="mutablePart">The part to insert.</param>
    /// <since>1.0.0</since>
    void InsertPart(size_t index, const ArcGISMutablePart& mutablePart);
    
    /// <summary>
    /// Remove all parts from the mutable part collection.
    /// </summary>
    /// <remarks>
    /// After calling this method the mutable part collection is empty.
    /// </remarks>
    /// <since>1.0.0</since>
    void RemoveAll();
    
    /// <summary>
    /// Removes a part from the mutable part collection.
    /// </summary>
    /// <param name="index">Zero-based index of the part.</param>
    /// <since>1.0.0</since>
    void RemovePart(size_t index);
    
    /// <summary>
    /// Replace a part in the mutable part collection at the specified part index.
    /// </summary>
    /// <param name="index">Zero-based index of the part</param>
    /// <param name="mutablePart">Collection of segments representing the part.</param>
    /// <since>1.0.0</since>
    void SetPart(size_t index, const ArcGISMutablePart& mutablePart);
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISMutablePartCollection(void* handle);
    ArcGISMutablePartCollection(const ArcGISMutablePartCollection&) = delete;
    ArcGISMutablePartCollection(ArcGISMutablePartCollection&& other) noexcept;
    ArcGISMutablePartCollection() = default;
    ~ArcGISMutablePartCollection();
    
    ArcGISMutablePartCollection& operator=(const ArcGISMutablePartCollection&) = delete;
    ArcGISMutablePartCollection& operator=(ArcGISMutablePartCollection&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri