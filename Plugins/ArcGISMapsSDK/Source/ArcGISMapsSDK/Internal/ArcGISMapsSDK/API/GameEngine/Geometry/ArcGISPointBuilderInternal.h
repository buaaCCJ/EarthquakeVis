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

/// <summary>
/// The point builder object is used to create a point.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISPointBuilderInternal
{
    friend class ArcGISPointBuilderInternal;

public:
    #pragma region Methods
    /// <summary>
    /// Adjusts the points's x-coordinate to be within the bounds of the assigned spatial reference.
    /// </summary>
    /// <since>1.0.0</since>
    static void Normalize(ArcGISPointBuilder* self);
    
    /// <summary>
    /// Normalizes the envelope to the passed in envelope.
    /// </summary>
    /// <param name="envelope">The envelope to normalize against.</param>
    /// <since>1.0.0</since>
    static void Normalize(ArcGISPointBuilder* self, const ArcGISEnvelope& envelope);
    
    /// <summary>
    /// Normalizes the point for wraparound.
    /// </summary>
    /// <param name="target">The target point within the spatial reference's bounds to normalize to.</param>
    /// <since>1.0.0</since>
    static void Normalize(ArcGISPointBuilder* self, const ArcGISPoint& target);
    #pragma endregion Methods
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri