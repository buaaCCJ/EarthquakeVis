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

#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeometryBuilder.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISMutablePartCollection;
class ArcGISPoint;

/// <summary>
/// The Multipart builder object is used to create a multipart geometry.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISMultipartBuilder :
    public ArcGISGeometryBuilder
{
public:
    #pragma region Properties
    /// <summary>
    /// New parts for the multipart builder.
    /// </summary>
    /// <remarks>
    /// The collection of parts for the multipart builder. Changes to the collection are reflected in the multipart builder.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISMutablePartCollection">ArcGISMutablePartCollection</seealso>
    /// <since>1.0.0</since>
    ArcGISMutablePartCollection GetParts() const;
    void SetParts(const ArcGISMutablePartCollection& parts);
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Adds a new point to the end of the last part of the multipart.
    /// </summary>
    /// <remarks>
    /// If there are no parts then an initial part is created and the point added to that.
    /// The point becomes the end point of a line segment in the part.
    /// </remarks>
    /// <param name="x">The x-coordinate of the point to add.</param>
    /// <param name="y">The y-coordinate of the point to add.</param>
    /// <returns>
    /// The point index of the new point in the last part.
    /// </returns>
    /// <since>1.0.0</since>
    size_t AddPoint(double x, double y);
    
    /// <summary>
    /// Adds a new point to the end of the last part of the multipart.
    /// </summary>
    /// <remarks>
    /// If there are no parts then an initial part is created and the point added to that.
    /// The point becomes the end point of a line segment in the part.
    /// </remarks>
    /// <param name="x">The x-coordinate of the point to add.</param>
    /// <param name="y">The y-coordinate of the point to add.</param>
    /// <param name="z">The z-coordinate of the point to add.</param>
    /// <returns>
    /// the point index of the new point in the last part
    /// </returns>
    /// <since>1.0.0</since>
    size_t AddPoint(double x, double y, double z);
    
    /// <summary>
    /// Adds a new point to the end of the last part of the multipart.
    /// </summary>
    /// <remarks>
    /// If there are no parts then an initial part is created and the point added to that.
    /// The point becomes the end point of a line segment in the part.
    /// </remarks>
    /// <param name="point">The point to add</param>
    /// <returns>
    /// the point index of the new point in the last part
    /// </returns>
    /// <since>1.0.0</since>
    size_t AddPoint(const ArcGISPoint& point);
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISMultipartBuilder(void* handle);
    ArcGISMultipartBuilder(const ArcGISMultipartBuilder&) = delete;
    ArcGISMultipartBuilder(ArcGISMultipartBuilder&& other) noexcept;
    ArcGISMultipartBuilder();
    virtual ~ArcGISMultipartBuilder() = default;
    
    ArcGISMultipartBuilder& operator=(const ArcGISMultipartBuilder&) = delete;
    ArcGISMultipartBuilder& operator=(ArcGISMultipartBuilder&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri