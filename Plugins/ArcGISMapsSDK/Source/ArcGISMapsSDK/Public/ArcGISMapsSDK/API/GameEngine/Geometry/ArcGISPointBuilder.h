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
class ArcGISPoint;
class ArcGISSpatialReference;

/// <summary>
/// The point builder object is used to create a point.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISPointBuilder :
    public ArcGISGeometryBuilder
{
    friend class ArcGISPointBuilderInternal;

public:
    #pragma region Constructors
    /// <summary>
    /// Creates a point builder from a point.
    /// </summary>
    /// <param name="point">The point object.</param>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</seealso>
    /// <since>1.0.0</since>
    ArcGISPointBuilder(const ArcGISPoint& point);
    
    /// <summary>
    /// Creates a point builder.
    /// </summary>
    /// <param name="spatialReference">The builder's spatial reference.</param>
    /// <since>1.0.0</since>
    ArcGISPointBuilder(const ArcGISSpatialReference& spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The m-value for the point.
    /// </summary>
    /// <remarks>
    /// Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetM() const;
    void SetM(double m);
    
    /// <summary>
    /// The x-coordinate for the point.
    /// </summary>
    /// <remarks>
    /// Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetX() const;
    void SetX(double x);
    
    /// <summary>
    /// The y-coordinate for the point.
    /// </summary>
    /// <remarks>
    /// Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetY() const;
    void SetY(double y);
    
    /// <summary>
    /// The z-coordinate for the point.
    /// </summary>
    /// <remarks>
    /// The minimum z-coordinate is -6,356,752 meters, which is the approximate radius of the earth (the WGS 84 datum semi-minor axis).
    /// The maximum z-coordinate is 55,000,000 meters. Will return NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetZ() const;
    void SetZ(double z);
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Offsets the envelope by the given offsets for the x and y dimension.
    /// </summary>
    /// <param name="offsetX">The number of units to move the envelope on the x axis.</param>
    /// <param name="offsetY">The number of units to move the envelope on the y axis.</param>
    /// <since>1.0.0</since>
    void OffsetBy(double offsetX, double offsetY);
    
    /// <summary>
    /// Sets the x,y coordinates of a point.
    /// </summary>
    /// <param name="x">The new x-coordinate value for the point.</param>
    /// <param name="y">The new y-coordinate value for the point.</param>
    /// <since>1.0.0</since>
    void SetXY(double x, double y);
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISPointBuilder(void* handle);
    ArcGISPointBuilder(const ArcGISPointBuilder&) = delete;
    ArcGISPointBuilder(ArcGISPointBuilder&& other) noexcept;
    ArcGISPointBuilder();
    virtual ~ArcGISPointBuilder() = default;
    
    ArcGISPointBuilder& operator=(const ArcGISPointBuilder&) = delete;
    ArcGISPointBuilder& operator=(ArcGISPointBuilder&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri