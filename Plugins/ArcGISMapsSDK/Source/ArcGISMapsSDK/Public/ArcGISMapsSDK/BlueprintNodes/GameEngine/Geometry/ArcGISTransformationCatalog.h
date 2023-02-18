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

#include "ArcGISTransformationCatalog.generated.h"

class UArcGISDatumTransformation;
class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISTransformationCatalog;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Allows discovery and management of the transformations used to convert coordinates between different datums.
/// </summary>
/// <remarks>
/// The transformation catalog class provides a mechanism for discovering available <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation">ArcGISDatumTransformation</see> objects.
/// You can retrieve the default transformation used internally to convert coordinates, and find
/// other available transformations. An area of interest may be taken into account.
/// 
/// This class also allows you to set the location where Projection Engine data files needed for some 
/// transformations are found on local storage. The <see cref="Esri::GameEngine::Geometry::ArcGISTransformationCatalog.projectionEngineDirectory">ArcGISTransformationCatalog.projectionEngineDirectory</see> property 
/// must be set before using any geometry classes.
/// 
/// The default transformation used when reprojecting geometries is the most suitable available transformation 
/// across the area covered by the input and output spatial references. You can sometimes get a more suitable 
/// transformation for work within a smaller area by specifying the extent of your specific work area, using 
/// <see cref="Esri::GameEngine::Geometry::ArcGISTransformationCatalog.getTransformation">ArcGISTransformationCatalog.getTransformation</see>.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISTransformationCatalog :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISTransformationCatalog")
    /// <summary>
    /// The directory of the Projection Engine files on the local file system.
    /// </summary>
    /// <remarks>
    /// This method should only be called immediately upon process startup before any other API method calls.
    /// </remarks>
    /// <since>1.0.0</since>
    static FString GetProjectionEngineDirectory();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISTransformationCatalog")
    /// <summary>
    /// The directory of the Projection Engine files on the local file system.
    /// </summary>
    /// <remarks>
    /// This method should only be called immediately upon process startup before any other API method calls.
    /// </remarks>
    /// <since>1.0.0</since>
    static void SetProjectionEngineDirectory(FString projectionEngineDirectory);
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISTransformationCatalog")
    /// <summary>
    /// Returns the best usable (default) transformation to transform between the input and output spatial
    /// references, without taking into account an area of interest.
    /// </summary>
    /// <remarks>
    /// The default transformation is the one used in cases such as calling <see cref="Esri::GameEngine::Geometry::ArcGISGeometryEngine.project">ArcGISGeometryEngine.project</see>
    /// without specifying a transformation.
    /// </remarks>
    /// <param name="inputSpatialReference">The spatial reference to use as the input.</param>
    /// <param name="outputSpatialReference">The spatial reference to use as the output.</param>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation">ArcGISDatumTransformation</see> instance that represents the best choice given the parameters. Always returns a
    /// usable transformation where <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation.isMissingProjectionEngineFiles">ArcGISDatumTransformation.isMissingProjectionEngineFiles</see> is false. Returns null if
    /// no usable transformation is available for the given input parameters, or if no transformation is required.
    /// 
    /// Prior to version 100.9, this method returned a <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformation">ArcGISGeographicTransformation</see>.
    /// 
    /// From version 100.9 onwards, if both inputSpatialReference and outputSpatialReference have a vertical 
    /// coordinate system, this method returns a <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformation">ArcGISHorizontalVerticalTransformation</see> instance. If either 
    /// <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> does not have a vertical coordinate system, a <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformation">ArcGISGeographicTransformation</see> is returned.
    /// To replicate the former behavior, use the <see cref="Esri::GameEngine::Geometry::ArcGISTransformationCatalog.getTransformation">ArcGISTransformationCatalog.getTransformation</see>
    /// method instead with 'ignoreVertical = true'.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISTransformationCatalog.getTransformation">ArcGISTransformationCatalog.getTransformation</seealso>
    /// <since>1.0.0</since>
    static UArcGISDatumTransformation* GetTransformation(UArcGISSpatialReference* inputSpatialReference, UArcGISSpatialReference* outputSpatialReference);
    #pragma endregion Methods
};