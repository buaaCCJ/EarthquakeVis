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
enum class ArcGISDatumTransformationType;

/// <summary>
/// Represents a function to convert between two coordinate systems.
/// </summary>
/// <remarks>
/// This is the base class for classes used to transform coordinates between spatial
/// references that have different datums. The inverse of the datum transformation,
/// used to transform in the opposite direction, may be accessed using a member
/// function.
/// 
/// A datum transformation has a name property intended to be suitable for display,
/// such as when displaying a list of available transformations to an end user.
/// 
/// You can get a list of suitable transformations for a given input and output spatial
/// reference using methods of the <see cref="Esri::GameEngine::Geometry::ArcGISTransformationCatalog">ArcGISTransformationCatalog</see> class. Some transformations
/// require that certain Projection Engine data files be present on the local file system.
/// The property <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation.isMissingProjectionEngineFiles">ArcGISDatumTransformation.isMissingProjectionEngineFiles</see> indicates whether
/// any of the files are missing. The complete list of necessary files is available using
/// the <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep.projectionEngineFilenames">ArcGISGeographicTransformationStep.projectionEngineFilenames</see> or
/// <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep.projectionEngineFilenames">ArcGISHorizontalVerticalTransformationStep.projectionEngineFilenames</see> properties.
/// 
/// In order for any Projection Engine files to be found, the data location must be set
/// first using the <see cref="Esri::GameEngine::Geometry::ArcGISTransformationCatalog.projectionEngineDirectory">ArcGISTransformationCatalog.projectionEngineDirectory</see> property.
/// 
/// A datum transformation object is immutable.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISDatumTransformationInternal
{
    friend class ArcGISDatumTransformationInternal;

public:
    #pragma region Properties
    /// <summary>
    /// The object type of this object.
    /// </summary>
    /// <since>1.0.0</since>
    static ArcGISDatumTransformationType GetObjectType(ArcGISDatumTransformation* self);
    #pragma endregion Properties
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri