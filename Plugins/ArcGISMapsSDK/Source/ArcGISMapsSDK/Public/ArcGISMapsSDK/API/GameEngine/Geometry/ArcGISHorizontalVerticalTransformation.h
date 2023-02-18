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
class ArcGISHorizontalVerticalTransformationStep;

/// <summary>
/// Used to transform coordinates of z-aware geometries between spatial references that have different
/// geographic and/or vertical coordinate systems.
/// </summary>
/// <remarks>
/// A HorizontalVerticalTransformation is an ordered list of <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see> objects. 
/// Each HorizontalVerticalTransformation has an input and an output <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see>, and this 
/// HorizontalVerticalTransformation object can be used to convert coordinates between the horizontal (geographic)
/// and vertical datums of these spatial references using the series of steps it contains. Use the 
/// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.project">ArcGISGeometryEngine.project</see> method to transform the coordinates
/// of a specific <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see>.
/// 
/// A horizontal transformation step is not needed when the input and output spatial references have the same 
/// underlying geographic coordinate systems. A vertical transformation is not needed if both datums (for 
/// ellipsoidal heights) or vertical datums (for gravity-related heights) are the same. To transform coordinates
/// only between different horizontal (geographic) coordinate systems, you can use a <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformation">ArcGISGeographicTransformation</see>
/// instead.
/// 
/// The inverse of this transformation, used to transform in the opposite direction, is returned from the
/// <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation.getInverse">ArcGISDatumTransformation.getInverse</see> method.
/// 
/// A HorizontalVerticalTransformation can be constructed from a single <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see>
/// object, or from a number of transformation step objects that are chained together.
/// 
/// You can get a list of suitable transformations for a given input and output spatial reference using one of the
/// methods on the <see cref="Esri::GameEngine::Geometry::ArcGISTransformationCatalog">ArcGISTransformationCatalog</see> class.
/// 
/// Some transformations require that certain Projection Engine data files be present on the local file system, 
/// and vertical transformation steps are especially likely to use such files, which can be very large in size.
/// The <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation.isMissingProjectionEngineFiles">ArcGISDatumTransformation.isMissingProjectionEngineFiles</see> property indicates whether any of the files are 
/// missing. The complete list of necessary files for each specific step is available using the 
/// <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep.projectionEngineFilenames">ArcGISHorizontalVerticalTransformationStep.projectionEngineFilenames</see> property.
/// 
/// A HorizontalVerticalTransformation object is immutable.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformation">ArcGISGeographicTransformation</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISHorizontalVerticalTransformation :
    public ArcGISDatumTransformation
{
public:
    #pragma region Constructors
    /// <summary>
    /// Create a multi-step transformation from one or more <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see> instances.
    /// </summary>
    /// <remarks>
    /// Use this constructor to create a horizontal-vertical transformation that has multiple steps.
    /// The output <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> of each step should match the input <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> of the 
    /// following step.
    /// </remarks>
    /// <param name="steps">An <see cref="Esri::Standard::ArcGISIntermediateImmutableArray">ArcGISIntermediateImmutableArray</see> containing <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see> instances.</param>
    /// <since>1.0.0</since>
    ArcGISHorizontalVerticalTransformation(const Unreal::ArcGISImmutableArray<ArcGISHorizontalVerticalTransformationStep>& steps);
    
    /// <summary>
    /// Create a single step transformation.
    /// </summary>
    /// <param name="step">A <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see> instance.</param>
    /// <since>1.0.0</since>
    ArcGISHorizontalVerticalTransformation(const ArcGISHorizontalVerticalTransformationStep& step);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The array of transformation steps that define this transformation.
    /// </summary>
    /// <since>1.0.0</since>
    Unreal::ArcGISImmutableArray<ArcGISHorizontalVerticalTransformationStep> GetSteps() const;
    #pragma endregion Properties

public:
    #pragma region Special Members
    explicit ArcGISHorizontalVerticalTransformation(void* handle);
    ArcGISHorizontalVerticalTransformation(const ArcGISHorizontalVerticalTransformation&) = delete;
    ArcGISHorizontalVerticalTransformation(ArcGISHorizontalVerticalTransformation&& other) noexcept;
    ArcGISHorizontalVerticalTransformation();
    virtual ~ArcGISHorizontalVerticalTransformation() = default;
    
    ArcGISHorizontalVerticalTransformation& operator=(const ArcGISHorizontalVerticalTransformation&) = delete;
    ArcGISHorizontalVerticalTransformation& operator=(ArcGISHorizontalVerticalTransformation&& other) = default;
    #pragma endregion Special Members
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri