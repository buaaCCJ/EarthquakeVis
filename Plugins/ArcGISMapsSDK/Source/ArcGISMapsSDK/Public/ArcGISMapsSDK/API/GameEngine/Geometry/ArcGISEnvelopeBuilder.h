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
class ArcGISEnvelope;
class ArcGISPoint;
class ArcGISSpatialReference;

/// <summary>
/// The envelope builder object is used to create an envelope.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISEnvelopeBuilder :
    public ArcGISGeometryBuilder
{
    friend class ArcGISEnvelopeBuilderInternal;

public:
    #pragma region Constructors
    /// <summary>
    /// Creates a envelope builder from a envelope.
    /// </summary>
    /// <param name="envelope">The envelope.</param>
    /// <since>1.0.0</since>
    ArcGISEnvelopeBuilder(const ArcGISEnvelope& envelope);
    
    /// <summary>
    /// Creates a envelope builder from a center point and a width and height.
    /// </summary>
    /// <param name="center">The center point for the envelope.</param>
    /// <param name="width">The width of the envelope around the center point.</param>
    /// <param name="height">The height of the envelope around the center point.</param>
    /// <since>1.0.0</since>
    ArcGISEnvelopeBuilder(const ArcGISPoint& center, double width, double height);
    
    /// <summary>
    /// Creates a envelope builder from a center point and a width, height, and depth.
    /// </summary>
    /// <param name="center">The center point for the envelope.</param>
    /// <param name="width">The width of the envelope around the center point.</param>
    /// <param name="height">The height of the envelope around the center point.</param>
    /// <param name="depth">The depth of the envelope around the center point.</param>
    /// <since>1.0.0</since>
    ArcGISEnvelopeBuilder(const ArcGISPoint& center, double width, double height, double depth);
    
    /// <summary>
    /// Creates a envelope builder.
    /// </summary>
    /// <param name="spatialReference">The builder's spatial reference.</param>
    /// <since>1.0.0</since>
    ArcGISEnvelopeBuilder(const ArcGISSpatialReference& spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The center point for the envelope builder.
    /// </summary>
    /// <remarks>
    /// Creates a new Point that must be destroyed.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</seealso>
    /// <since>1.0.0</since>
    ArcGISPoint GetCenter() const;
    
    /// <summary>
    /// The depth (ZMax - ZMin) for the envelope builder.
    /// </summary>
    /// <remarks>
    /// A 2D
    /// envelope has zero depth. Returns NAN if the envelope is empty or if
    /// an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetDepth() const;
    
    /// <summary>
    /// The height for the envelope builder.
    /// </summary>
    /// <remarks>
    /// The width for the envelope builder. Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetHeight() const;
    
    /// <summary>
    /// The m maximum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetMMax() const;
    void SetMMax(double mMax);
    
    /// <summary>
    /// The m minimum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetMMin() const;
    void SetMMin(double mMin);
    
    /// <summary>
    /// The width for the envelope builder.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetWidth() const;
    
    /// <summary>
    /// The x maximum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetXMax() const;
    void SetXMax(double xMax);
    
    /// <summary>
    /// The x minimum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetXMin() const;
    void SetXMin(double xMin);
    
    /// <summary>
    /// The y maximum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetYMax() const;
    void SetYMax(double yMax);
    
    /// <summary>
    /// The y minimum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetYMin() const;
    void SetYMin(double yMin);
    
    /// <summary>
    /// The z maximum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetZMax() const;
    void SetZMax(double zMax);
    
    /// <summary>
    /// The z minimum value for the envelope.
    /// </summary>
    /// <remarks>
    /// Returns NAN if an error occurs.
    /// </remarks>
    /// <since>1.0.0</since>
    double GetZMin() const;
    void SetZMin(double zMin);
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Centers the envelope over the given point.
    /// </summary>
    /// <param name="point">The point to center on.</param>
    /// <since>1.0.0</since>
    void CenterAt(const ArcGISPoint& point);
    
    /// <summary>
    /// Adjust the envelope's aspect ratio to match the ratio of the given width and height.
    /// </summary>
    /// <remarks>
    /// The operation preserves the center of the envelope and only increases either height or width, not both.
    /// If the new width would be greater than the old, the width is changed and the height remains the same.
    /// If the new width would be less than or equal to the old, the height is changed and the width remains the same.
    /// </remarks>
    /// <param name="width">A width.</param>
    /// <param name="height">A height.</param>
    /// <since>1.0.0</since>
    void ChangeAspectRatio(double width, double height);
    
    /// <summary>
    /// Expands the envelope by the given scale factor.
    /// </summary>
    /// <param name="factor">Values less than 1 zoom in and values greater than 1 zoom out.</param>
    /// <since>1.0.0</since>
    void Expand(double factor);
    
    /// <summary>
    /// Expands the envelope at the anchor point by the given factor.
    /// </summary>
    /// <param name="anchor">The point to anchor at.</param>
    /// <param name="factor">Values less than 1 zoom in and values greater than 1 zoom out.</param>
    /// <since>1.0.0</since>
    void Expand(const ArcGISPoint& anchor, double factor);
    
    /// <summary>
    /// Offsets the envelope by the given offsets for the x and y dimension.
    /// </summary>
    /// <param name="offsetX">The number of units to move the envelope on the x axis.</param>
    /// <param name="offsetY">The number of units to move the envelope on the y axis.</param>
    /// <since>1.0.0</since>
    void OffsetBy(double offsetX, double offsetY);
    
    /// <summary>
    /// Set the m-values for the envelope.
    /// </summary>
    /// <param name="mMin">The m minimum value for the envelope.</param>
    /// <param name="mMax">The m maximum value for the envelope.</param>
    /// <since>1.0.0</since>
    void SetM(double mMin, double mMax);
    
    /// <summary>
    /// Set the x,y coordinates for the envelope.
    /// </summary>
    /// <param name="xMin">The x minimum value for the envelope.</param>
    /// <param name="yMin">The y minimum value for the envelope.</param>
    /// <param name="xMax">The x maximum value for the envelope.</param>
    /// <param name="yMax">The y maximum value for the envelope.</param>
    /// <since>1.0.0</since>
    void SetXY(double xMin, double yMin, double xMax, double yMax);
    
    /// <summary>
    /// Set the z-values for the envelope.
    /// </summary>
    /// <param name="zMin">The z minimum value for the envelope.</param>
    /// <param name="zMax">The z maximum value for the envelope.</param>
    /// <since>1.0.0</since>
    void SetZ(double zMin, double zMax);
    
    /// <summary>
    /// Finds the union of this envelope and the given envelope and updates the envelope builder with the result.
    /// </summary>
    /// <param name="envelope">Another envelope to union with.</param>
    /// <since>1.0.0</since>
    void Union(const ArcGISEnvelope& envelope);
    
    /// <summary>
    /// Finds the union of this envelope and the given point and updates the envelope builder with the result.
    /// </summary>
    /// <param name="point">A point to union with.</param>
    /// <since>1.0.0</since>
    void Union(const ArcGISPoint& point);
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISEnvelopeBuilder(void* handle);
    ArcGISEnvelopeBuilder(const ArcGISEnvelopeBuilder&) = delete;
    ArcGISEnvelopeBuilder(ArcGISEnvelopeBuilder&& other) noexcept;
    ArcGISEnvelopeBuilder();
    virtual ~ArcGISEnvelopeBuilder() = default;
    
    ArcGISEnvelopeBuilder& operator=(const ArcGISEnvelopeBuilder&) = delete;
    ArcGISEnvelopeBuilder& operator=(ArcGISEnvelopeBuilder&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri