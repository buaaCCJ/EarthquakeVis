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
enum class ArcGISGeometryBuilderType;

/// <summary>
/// A geometry builder object
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISGeometryBuilderInternal
{
    friend class ArcGISGeometryBuilderInternal;

public:
    #pragma region Properties
    /// <summary>
    /// The type of geometry builder.
    /// </summary>
    /// <remarks>
    /// The geometry builder type for a specific geometry builder. Returns <see cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilderType.unknown">ArcGISGeometryBuilderType.unknown</see> if an error occurs.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometryBuilderType">ArcGISGeometryBuilderType</seealso>
    /// <since>1.0.0</since>
    static ArcGISGeometryBuilderType GetObjectType(ArcGISGeometryBuilder* self);
    #pragma endregion Properties
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri