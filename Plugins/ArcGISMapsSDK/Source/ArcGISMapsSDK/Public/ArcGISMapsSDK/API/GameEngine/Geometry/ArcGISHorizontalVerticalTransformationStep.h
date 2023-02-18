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
namespace Unreal
{
template<typename T> class ArcGISImmutableArray;
} // namespace Unreal

namespace GameEngine
{
namespace Geometry
{
/// <summary>
/// Represents a step in the process of transforming between horizontal and/or vertical datums.
/// </summary>
/// <remarks>
/// Each <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see> can be constructed from a well-known ID (WKID) that represents a
/// horizontal (geographic) or a vertical transformation. This API supports thousands of predefined
/// transformations, and all the supported WKIDs are documented in the 'Coordinate systems and transformations'
/// topic in the developers guide.
/// 
/// One or more <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see> objects are combined into a <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformation">ArcGISHorizontalVerticalTransformation</see> object, and
/// can then be used to control how coordinates are transformed in a
/// <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.project">ArcGISGeometryEngine.project</see> method call.
/// 
/// A <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see> object is immutable.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformation">ArcGISHorizontalVerticalTransformation</seealso>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep">ArcGISGeographicTransformationStep</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISHorizontalVerticalTransformationStep
{
public:
    #pragma region Constructors
    /// <summary>
    /// Creates a new <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see> instance from a well-known ID.
    /// </summary>
    /// <remarks>
    /// Occasionally, WKIDs may change, and older codes may be deprecated in favor of a new code. Both old
    /// (deprecated) and new (latest) WKIDs continue to work for instantiation, as long as they are supported
    /// by the Projection Engine. The <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep.WKID">ArcGISHorizontalVerticalTransformationStep.WKID</see> property returns the new
    /// (latest) WKID code.
    /// </remarks>
    /// <param name="WKID">The well-known ID of the transformation step to create.</param>
    /// <since>1.0.0</since>
    ArcGISHorizontalVerticalTransformationStep(int32_t WKID);
    
    /// <summary>
    /// Creates a new <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see> instance from a well-known text string.
    /// </summary>
    /// <param name="WKText">The well-known text of the transformation step to create.</param>
    /// <since>1.0.0</since>
    ArcGISHorizontalVerticalTransformationStep(const FString& WKText);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// True if this transformation step instance is an inverted transformation.
    /// </summary>
    /// <remarks>
    /// Transformations have a specific direction that is indicated by the
    /// <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep.WKText">ArcGISHorizontalVerticalTransformationStep.WKText</see> value. An inverted transformation is used to transform
    /// geometries in the opposite direction to that indicated by the well-known text.
    /// <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see> has <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation.inputSpatialReference">ArcGISDatumTransformation.inputSpatialReference</see> and
    /// <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation.outputSpatialReference">ArcGISDatumTransformation.outputSpatialReference</see> properties that respect the inverse value of the contained
    /// transformation(s).
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep.getInverse">ArcGISHorizontalVerticalTransformationStep.getInverse</seealso>
    /// <since>1.0.0</since>
    bool GetIsInverse() const;
    
    /// <summary>
    /// True if any files needed by the Projection Engine for this transformation step are missing from the local
    /// file system.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsMissingProjectionEngineFiles() const;
    
    /// <summary>
    /// A list of the Projection Engine files required to support this transformation step.
    /// </summary>
    /// <remarks>
    /// Each name in the list includes the full path. Projection Engine datasets are used in grid-based transforms.
    /// </remarks>
    /// <since>1.0.0</since>
    Unreal::ArcGISImmutableArray<FString> GetProjectionEngineFilenames() const;
    
    /// <summary>
    /// The well-known ID or 0 if the transformation in this step does not have a well-known ID.
    /// </summary>
    /// <remarks>
    /// Occasionally, WKIDs may change, and an older code may be deprecated in favor of a new code. This property
    /// returns the new (latest) WKID code.
    /// </remarks>
    /// <since>1.0.0</since>
    int32_t GetWKID() const;
    
    /// <summary>
    /// The well-known text of this transformation step instance.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetWKText() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Tests if this object is equal to a second <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see> object.
    /// </summary>
    /// <param name="rightHorizontalVerticalTransformationStep">Another <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see>.</param>
    /// <returns>
    /// True if the comparison succeeds and the objects are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(const ArcGISHorizontalVerticalTransformationStep& rightHorizontalVerticalTransformationStep) const;
    
    /// <summary>
    /// Returns the inverse of this transformation step or null if the transformation is not invertible.
    /// </summary>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</see> representing the inverse or null if an inverse does not exist.
    /// </returns>
    /// <since>1.0.0</since>
    ArcGISHorizontalVerticalTransformationStep GetInverse() const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISHorizontalVerticalTransformationStep(void* handle);
    ArcGISHorizontalVerticalTransformationStep(const ArcGISHorizontalVerticalTransformationStep&) = delete;
    ArcGISHorizontalVerticalTransformationStep(ArcGISHorizontalVerticalTransformationStep&& other) noexcept;
    ArcGISHorizontalVerticalTransformationStep() = default;
    ~ArcGISHorizontalVerticalTransformationStep();
    
    ArcGISHorizontalVerticalTransformationStep& operator=(const ArcGISHorizontalVerticalTransformationStep&) = delete;
    ArcGISHorizontalVerticalTransformationStep& operator=(ArcGISHorizontalVerticalTransformationStep&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri