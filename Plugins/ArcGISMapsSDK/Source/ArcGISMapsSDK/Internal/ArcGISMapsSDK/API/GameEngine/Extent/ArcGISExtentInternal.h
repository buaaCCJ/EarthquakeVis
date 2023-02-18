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
namespace Extent
{
enum class ArcGISExtentType;

/// <summary>
/// Abstract class of any kind of extent
/// </summary>
/// <remarks>
/// Abstract class of any kind of extent.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISExtentInternal
{
    friend class ArcGISExtentInternal;

public:
    #pragma region Properties
    /// <summary>
    /// Extent type
    /// </summary>
    /// <since>1.0.0</since>
    static ArcGISExtentType GetObjectType(ArcGISExtent* self);
    #pragma endregion Properties
};
} // namespace Extent
} // namespace GameEngine
} // namespace Esri