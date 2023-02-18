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
template<typename Key, typename Value> class ArcGISDictionary;
} // namespace Unreal

namespace Standard
{
class ArcGISElement;
enum class ArcGISElementType;

/// <summary>
/// Defines a dictionary object.
/// </summary>
/// <remarks>
/// There are a couple of performance optimizations to consider with the generic collection type:
/// 1.  The <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> object can be reused for multiple calls while adding/inserting/updating values within
/// the collection.  So you can instantiate one <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> and iteratively change its value and call
/// add/update/insert on the collection to modify the values of the collection.
/// 2.  If the overhead of creating these <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> does become too much for a specific value type, then
/// consider subclassing the collection type and provide "overloaded" methods that would accept that value type
/// directly.  This would eliminate the overhead of instantiating these <see cref="Esri::Standard::ArcGISElement">ArcGISElement</see> objects.
/// </remarks>
/// <since>1.0.0</since>
class ArcGISIntermediateDictionary
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a dictionary. This allocates memory that must be deleted.
    /// </summary>
    /// <param name="keyType">The type of the dictionary's key.</param>
    /// <param name="valueType">The type of the dictionary's value.</param>
    /// <since>1.0.0</since>
    ArcGISIntermediateDictionary(ArcGISElementType keyType, ArcGISElementType valueType);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The type of the keys this dictionary holds.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISElementType GetKeyType() const;
    
    /// <summary>
    /// Determines the number of values in the dictionary.
    /// </summary>
    /// <remarks>
    /// The number of values in the dictionary. If an error occurs a 0 will be returned.
    /// </remarks>
    /// <since>1.0.0</since>
    size_t GetSize() const;
    
    /// <summary>
    /// The type of the values this dictionary holds.
    /// </summary>
    /// <since>1.0.0</since>
    ArcGISElementType GetValueType() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Get a value for a specific key.
    /// </summary>
    /// <remarks>
    /// Retrieves the value for the specified key.
    /// </remarks>
    /// <param name="key">The key which you want to get the value.</param>
    /// <returns>
    /// The value for the key requested. A null if an error occurs or the key doesn't exist.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISElement At(const ArcGISElement& key) const;
    
    /// <summary>
    /// Does the dictionary contain a key.
    /// </summary>
    /// <remarks>
    /// Does the dictionary contain a specific key.
    /// </remarks>
    /// <param name="key">The key you want to find.</param>
    /// <returns>
    /// True if the key is in the dictionary otherwise false.
    /// </returns>
    /// <since>1.0.0</since>
    bool Contains(const ArcGISElement& key) const;
    
    /// <summary>
    /// Returns true if the two dictionaries are equal, false otherwise.
    /// </summary>
    /// <param name="dictionary2">The second dictionary.</param>
    /// <returns>
    /// Returns true if the two dictionaries are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(const Unreal::ArcGISDictionary<ArcGISElement, ArcGISElement>& dictionary2) const;
    
    /// <summary>
    /// Returns the type that the value of a given key should be, if the dictionary instance supports it.  Otherwise, <see cref="Esri::Standard::ArcGISElementType.variant">ArcGISElementType.variant</see> will be returned.
    /// </summary>
    /// <param name="key">The key you want to now the value type for.</param>
    /// <returns>
    /// An <see cref="Esri::Standard::ArcGISElementType">ArcGISElementType</see> value, or <see cref="Esri::Standard::ArcGISElementType.variant">ArcGISElementType.variant</see> if an error occurs or the dictionary does not support the type lookup.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISElementType GetTypeForKey(const ArcGISElement& key) const;
    
    /// <summary>
    /// Insert a value for a given key in the dictionary.
    /// </summary>
    /// <remarks>
    /// Insert a value at a specified key position to the dictionary.
    /// </remarks>
    /// <param name="key">The key position which you want to insert the value.</param>
    /// <param name="value">The value that is to be added.</param>
    /// <since>1.0.0</since>
    void Insert(const ArcGISElement& key, const ArcGISElement& value);
    
    /// <summary>
    /// Determines if there are any values in the dictionary.
    /// </summary>
    /// <remarks>
    /// Check if the dictionary object has any values in it.
    /// </remarks>
    /// <returns>
    /// true if the dictionary object contains no values otherwise false. Will return true if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    bool IsEmpty() const;
    
    /// <summary>
    /// Remove a value at a specific key position in the dictionary.
    /// </summary>
    /// <remarks>
    /// Remove a value at a specific position in the dictionary.
    /// </remarks>
    /// <param name="key">The key position which you want to remove the value.</param>
    /// <since>1.0.0</since>
    void Remove(const ArcGISElement& key);
    
    /// <summary>
    /// Remove all values from the dictionary.
    /// </summary>
    /// <since>1.0.0</since>
    void RemoveAll();
    
    /// <summary>
    /// Replace a value at a specific key position in the dictionary.
    /// </summary>
    /// <param name="key">The key position which you want to replace the value.</param>
    /// <param name="newValue">The new value.</param>
    /// <since>1.0.0</since>
    void Replace(const ArcGISElement& key, const ArcGISElement& newValue);
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISIntermediateDictionary(void* handle);
    
    ArcGISIntermediateDictionary(const ArcGISIntermediateDictionary&) = delete;
    
    ArcGISIntermediateDictionary(ArcGISIntermediateDictionary&& other) noexcept;
    
    ArcGISIntermediateDictionary() = default;
    
    ~ArcGISIntermediateDictionary();
    
    ArcGISIntermediateDictionary& operator=(const ArcGISIntermediateDictionary&) = delete;
    
    ArcGISIntermediateDictionary& operator=(ArcGISIntermediateDictionary&& other) noexcept;
    
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Standard
} // namespace Esri