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

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "ArcGISGeographicTransformationStep.generated.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISGeographicTransformationStep;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Represents a step in the process of transforming between datums.
/// </summary>
/// <remarks>
/// Each geographic transformation step can be constructed from a well-known ID
/// (WKID) that represents a geographic transformation. Because the Projection
/// Engine supports thousands of transformations, WKIDs are not presented in the
/// SDK as enumerations. Instead, they are documented in the developers guide.
/// 
/// The list of supported WKIDs includes a transformation from every supported
/// datum to WGS 1984. Additionally, there is more limited list of
/// transformations directly between two non-WGS84 datums, such as
/// 4461, which is NAD_1983_HARN_To_NAD_1983_NSRS2007_1.
/// 
/// Transformations with more than one step typically go via WGS84, with one
/// forward and one inverse geographic transformation chained together to get the
/// required geographic coordinates.
/// 
/// A geographic transformation step object is immutable.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformation">ArcGISGeographicTransformation</seealso>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformationStep">ArcGISHorizontalVerticalTransformationStep</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISGeographicTransformationStep :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeographicTransformationStep")
    /// <summary>
    /// Creates a new <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep">ArcGISGeographicTransformationStep</see> instance from a well-known ID.
    /// </summary>
    /// <remarks>
    /// Occasionally, WKIDs may change, and older codes may be deprecated in favor of a new code. Both old
    /// (deprecated) and new (latest) WKIDs continue to work for instantiation, as long as they are supported
    /// by the Projection Engine. The <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep.WKID">ArcGISGeographicTransformationStep.WKID</see> property returns the new (latest)
    /// WKID code.
    /// </remarks>
    /// <param name="WKID">The well-known ID of the geographic transformation step to create.</param>
    /// <since>1.0.0</since>
    static UArcGISGeographicTransformationStep* CreateArcGISGeographicTransformationStepWithWKID(int32 WKID);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeographicTransformationStep")
    /// <summary>
    /// Creates a new <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep">ArcGISGeographicTransformationStep</see> instance from a well-known text string.
    /// </summary>
    /// <param name="WKText">The well-known text of the geographic transformation step to create.</param>
    /// <since>1.0.0</since>
    static UArcGISGeographicTransformationStep* CreateArcGISGeographicTransformationStepWithWKText(FString WKText);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeographicTransformationStep")
    /// <summary>
    /// True if this geographic transformation step instance is an inverted transformation.
    /// </summary>
    /// <remarks>
    /// Transformations have a specific direction that is indicated by the
    /// <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep.WKText">ArcGISGeographicTransformationStep.WKText</see> value. An inverted transformation is used to transform
    /// geometries in the opposite direction to that indicated by the well-known text. <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformation">ArcGISGeographicTransformation</see>
    /// has <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation.inputSpatialReference">ArcGISDatumTransformation.inputSpatialReference</see> and <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation.outputSpatialReference">ArcGISDatumTransformation.outputSpatialReference</see>
    /// properties that respect the inverse value of the contained transformation(s).
    /// 
    /// This API supports a large number of transformation WKIDs, including transformations from every
    /// supported datum to the World Geodetic System 1984 (WGS84) datum. To transform coordinates between two
    /// non-WGS84 datums, typically one forward and one inverse <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep">ArcGISGeographicTransformationStep</see> are added
    /// to a <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformation">ArcGISGeographicTransformation</see>, to get the required inputs and outputs.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep.getInverse">ArcGISGeographicTransformationStep.getInverse</seealso>
    /// <since>1.0.0</since>
    bool GetIsInverse();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeographicTransformationStep")
    /// <summary>
    /// True if any files needed by the Projection Engine for this
    /// geographic transformation step are missing from the local file system.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsMissingProjectionEngineFiles();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeographicTransformationStep")
    /// <summary>
    /// The well-known ID, or 0 if the transformation in this step does not have a well-known ID.
    /// </summary>
    /// <remarks>
    /// Occasionally, WKIDs may change, and an older code may be deprecated in favor of a new code. This property
    /// returns the new (latest) WKID code.
    /// </remarks>
    /// <since>1.0.0</since>
    int32 GetWKID();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeographicTransformationStep")
    /// <summary>
    /// The well-known text of this geographic transformation step instance.
    /// </summary>
    /// <remarks>
    /// This value does not respect the <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep.isInverse">ArcGISGeographicTransformationStep.isInverse</see> property.
    /// </remarks>
    /// <since>1.0.0</since>
    FString GetWKText();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeographicTransformationStep")
    /// <summary>
    /// Tests if this object is equal to a second <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep">ArcGISGeographicTransformationStep</see> object.
    /// </summary>
    /// <param name="rightGeographicTransformationStep">Another geographic transformation step.</param>
    /// <returns>
    /// True if the comparison succeeds and the objects are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(UArcGISGeographicTransformationStep* rightGeographicTransformationStep) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeographicTransformationStep")
    /// <summary>
    /// Returns the inverse of this geographic transformation step or null if the transformation is not invertible.
    /// </summary>
    /// <returns>
    /// An <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep">ArcGISGeographicTransformationStep</see> representing the inverse or null if an inverse does not exist.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISGeographicTransformationStep* GetInverse() const;
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep> APIObject;
};