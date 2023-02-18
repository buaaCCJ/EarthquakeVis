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

#include "ArcGISDatumTransformation.generated.h"

class UArcGISSpatialReference;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISDatumTransformation;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
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
class ARCGISMAPSSDK_API UArcGISDatumTransformation :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISDatumTransformation")
    /// <summary>
    /// The input <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see>.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetInputSpatialReference();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISDatumTransformation")
    /// <summary>
    /// True if the dataset needed by the Projection Engine is missing from the local file system.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsMissingProjectionEngineFiles();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISDatumTransformation")
    /// <summary>
    /// The name of the datum transformation.
    /// </summary>
    /// <remarks>
    /// For multi-step transformations, the name contains the concatenated names of
    /// each step's transformation, separated by a plus sign '+'. If the transformation is
    /// inverted, the name starts with a tilde (~).
    /// </remarks>
    /// <since>1.0.0</since>
    FString GetName();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISDatumTransformation")
    /// <summary>
    /// The output <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see>.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetOutputSpatialReference();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISDatumTransformation")
    /// <summary>
    /// Tests if this object is equal to a second <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation">ArcGISDatumTransformation</see> object.
    /// </summary>
    /// <param name="rightDatumTransformation">Another datum transformation.</param>
    /// <returns>
    /// True if the comparison succeeds and the objects are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(UArcGISDatumTransformation* rightDatumTransformation) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISDatumTransformation")
    /// <summary>
    /// Returns the inverse of this datum transformation.
    /// </summary>
    /// <returns>
    /// A <see cref="Esri::GameEngine::Geometry::ArcGISDatumTransformation">ArcGISDatumTransformation</see> representing the inverse, or null if an inverse for this data transformation does not exist.
    /// </returns>
    /// <since>1.0.0</since>
    UArcGISDatumTransformation* GetInverse() const;
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISDatumTransformation> APIObject;
};