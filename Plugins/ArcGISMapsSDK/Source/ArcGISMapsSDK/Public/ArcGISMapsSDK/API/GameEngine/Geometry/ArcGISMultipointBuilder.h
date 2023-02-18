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
class ArcGISMultipoint;
class ArcGISMutablePointCollection;
class ArcGISSpatialReference;

/// <summary>
/// The multipoint builder object is used to create a multipoint.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISMultipointBuilder :
    public ArcGISGeometryBuilder
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a multipoint builder from a multipoint.
    /// </summary>
    /// <param name="multipoint">A multipoint object.</param>
    /// <since>1.0.0</since>
    ArcGISMultipointBuilder(const ArcGISMultipoint& multipoint);
    
    /// <summary>
    /// Creates a multipoint builder.
    /// </summary>
    /// <param name="spatialReference">The builder's spatial reference.</param>
    /// <since>1.0.0</since>
    ArcGISMultipointBuilder(const ArcGISSpatialReference& spatialReference);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// A mutable collection of points.
    /// </summary>
    /// <remarks>
    /// Use this collection to add points to or remove points from the builder.
    /// </remarks>
    /// <since>1.0.0</since>
    ArcGISMutablePointCollection GetPoints() const;
    void SetPoints(const ArcGISMutablePointCollection& points);
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISMultipointBuilder(void* handle);
    ArcGISMultipointBuilder(const ArcGISMultipointBuilder&) = delete;
    ArcGISMultipointBuilder(ArcGISMultipointBuilder&& other) noexcept;
    ArcGISMultipointBuilder();
    virtual ~ArcGISMultipointBuilder() = default;
    
    ArcGISMultipointBuilder& operator=(const ArcGISMultipointBuilder&) = delete;
    ArcGISMultipointBuilder& operator=(ArcGISMultipointBuilder&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri