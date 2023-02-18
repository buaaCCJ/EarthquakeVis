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

/// <summary>
/// The envelope builder object is used to create an envelope.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISEnvelopeBuilderInternal
{
    friend class ArcGISEnvelopeBuilderInternal;

public:
    #pragma region Methods
    /// <summary>
    /// Adjusts the envelope to be within the bounds of its spatial reference's extent.
    /// </summary>
    /// <returns>
    /// An envelope object adjusted for wraparound or null if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    static ArcGISEnvelope AdjustForWrapAround(ArcGISEnvelopeBuilder* self);
    
    /// <summary>
    /// Adjusts the envelope's x-values to be within the bounds of the assigned spatial reference.
    /// </summary>
    /// <since>1.0.0</since>
    static void Normalize(ArcGISEnvelopeBuilder* self);
    
    /// <summary>
    /// Normalizes the envelope to the passed in envelope.
    /// </summary>
    /// <param name="envelope">The envelope to normalize against.</param>
    /// <since>1.0.0</since>
    static void Normalize(ArcGISEnvelopeBuilder* self, const ArcGISEnvelope& envelope);
    #pragma endregion Methods
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri