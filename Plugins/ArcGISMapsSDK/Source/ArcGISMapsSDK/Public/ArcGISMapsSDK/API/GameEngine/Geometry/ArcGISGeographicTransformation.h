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

#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISDatumTransformation.h"

namespace Esri
{
namespace Unreal
{
template<typename T> class ArcGISImmutableArray;
} // namespace Unreal

namespace GameEngine
{
namespace Geometry
{
class ArcGISGeographicTransformationStep;

/// <summary>
/// Used to transform coordinates of geometries between spatial references that have two different geographic
/// coordinate systems.
/// </summary>
/// <remarks>
/// Each geographic transformation has an input and an output spatial reference.
/// The transformation operates on the horizontal (geographic) datums in each spatial reference.
/// 
/// The inverse of the geographic transformation, if any, used to transform in the
/// opposite direction, may be accessed using a member function.
/// 
/// A geographic transformation can be constructed from a single
/// geographic transformation step object, or from a list of geographic
/// transformation steps objects that are chained together. Most transformations
/// between spatial references that do not share the WGS 1984 datum use WGS 1984
/// as an intermediate datum. Thus, it is common to create a
/// geographic transformation object with two geographic transformation steps:
/// first to transform from the datum in the input spatial reference to WGS 1984,
/// and then from WGS 1984 to the output spatial reference's datum. There are a
/// limited number of transformations directly between two non-WGS84 datums, such
/// as WKID 4461, which is NAD_1983_HARN_To_NAD_1983_NSRS2007_1. These do not
/// need WGS 1984 as an intermediate datum.
/// 
/// In most cases, you do not need to construct your own <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformation">ArcGISGeographicTransformation</see>.
/// You can get a list of suitable transformations for a given input and output
/// spatial reference using one of the functions on the transformation catalog class.
/// 
/// A geographic transformation object is immutable.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISGeographicTransformation :
    public ArcGISDatumTransformation
{
public:
    #pragma region Constructors
    /// <summary>
    /// Create a multi-step transformation from one or more <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep">ArcGISGeographicTransformationStep</see> instances.
    /// </summary>
    /// <remarks>
    /// Use this when the multi-step transformation is known in advance.
    /// The output of each step should match the input of the following step. Then,
    /// you can use the new multi-step transformation where you would use a
    /// single-step transformation.
    /// </remarks>
    /// <param name="steps">An <see cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</see> containing <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep">ArcGISGeographicTransformationStep</see> instances.</param>
    /// <since>1.0.0</since>
    ArcGISGeographicTransformation(const Unreal::ArcGISImmutableArray<ArcGISGeographicTransformationStep>& steps);
    
    /// <summary>
    /// Create a single step transformation.
    /// </summary>
    /// <param name="step">A <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep">ArcGISGeographicTransformationStep</see> instance.</param>
    /// <since>1.0.0</since>
    ArcGISGeographicTransformation(const ArcGISGeographicTransformationStep& step);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The array of geographic transformation steps that define this geographic transformation.
    /// </summary>
    /// <since>1.0.0</since>
    Unreal::ArcGISImmutableArray<ArcGISGeographicTransformationStep> GetSteps() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISGeographicTransformation(void* handle);
    ArcGISGeographicTransformation(const ArcGISGeographicTransformation&) = delete;
    ArcGISGeographicTransformation(ArcGISGeographicTransformation&& other) noexcept;
    ArcGISGeographicTransformation();
    virtual ~ArcGISGeographicTransformation() = default;
    
    ArcGISGeographicTransformation& operator=(const ArcGISGeographicTransformation&) = delete;
    ArcGISGeographicTransformation& operator=(ArcGISGeographicTransformation&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri