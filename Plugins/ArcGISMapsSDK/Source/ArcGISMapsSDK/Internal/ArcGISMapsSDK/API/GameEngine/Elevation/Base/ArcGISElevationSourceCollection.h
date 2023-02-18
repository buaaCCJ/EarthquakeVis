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
template<typename T> class ArcGISCollection;
} // namespace Unreal

namespace GameEngine
{
namespace Elevation
{
namespace Base
{
class ArcGISElevationSource;

/// <summary>
/// Defines a dynamic array that provides callbacks when ArcGISElevationSource(s) are added or removed.
/// </summary>
/// <remarks>
/// The vector holds <see cref="Esri::GameEngine::Elevation::Base::ArcGISElevationSource">ArcGISElevationSource</see> objects.
/// </remarks>
/// <since>1.0.0</since>
class ArcGISElevationSourceCollection
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a vector. This allocates memory that must be deleted.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISElevationSourceCollection();
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
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Add a value to the vector.
    /// </summary>
    /// <param name="value">The value that is to be added.</param>
    /// <returns>
    /// The position of the value. Max value of size_t if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    size_t Add(const ArcGISElevationSource& value);
    
    /// <summary>
    /// Appends a vector to a vector.
    /// </summary>
    /// <param name="vector2">The value that is to be added.</param>
    /// <returns>
    /// The new size of vector_1. Max value of size_t if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    size_t AddArray(const Unreal::ArcGISCollection<ArcGISElevationSource>& vector2);
    
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
    ArcGISElevationSource At(size_t position) const;
    
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
    bool Contains(const ArcGISElevationSource& value) const;
    
    /// <summary>
    /// Returns true if the two vectors are equal, false otherwise.
    /// </summary>
    /// <param name="vector2">The second vector.</param>
    /// <returns>
    /// Returns true if the two vectors are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(const Unreal::ArcGISCollection<ArcGISElevationSource>& vector2) const;
    
    /// <summary>
    /// Get the first value in the vector.
    /// </summary>
    /// <returns>
    /// The value, <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISElevationSource First() const;
    
    /// <summary>
    /// Retrieves the position of the given value in the vector.
    /// </summary>
    /// <param name="value">The value you want to find.</param>
    /// <returns>
    /// The position of the value in the vector, Max value of size_t otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    size_t IndexOf(ArcGISElevationSource& value) const;
    
    /// <summary>
    /// Insert a value at the specified position in the vector.
    /// </summary>
    /// <remarks>
    /// Insert a value at a specified position to the vector.
    /// </remarks>
    /// <param name="position">The position which you want to insert the value.</param>
    /// <param name="value">The value that is to be added.</param>
    /// <since>1.0.0</since>
    void Insert(size_t position, const ArcGISElevationSource& value);
    
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
    /// The value, <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see>, at the position requested.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISElevationSource Last() const;
    
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

public:
    #pragma region Special Members
    explicit ArcGISElevationSourceCollection(void* handle);
    ArcGISElevationSourceCollection(const ArcGISElevationSourceCollection&) = delete;
    ArcGISElevationSourceCollection(ArcGISElevationSourceCollection&& other) noexcept;
    ~ArcGISElevationSourceCollection();
    
    ArcGISElevationSourceCollection& operator=(const ArcGISElevationSourceCollection&) = delete;
    ArcGISElevationSourceCollection& operator=(ArcGISElevationSourceCollection&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Base
} // namespace Elevation
} // namespace GameEngine
} // namespace Esri