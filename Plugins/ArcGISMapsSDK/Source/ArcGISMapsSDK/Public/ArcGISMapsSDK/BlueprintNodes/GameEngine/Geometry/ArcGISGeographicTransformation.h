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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISDatumTransformation.h"

#include "ArcGISGeographicTransformation.generated.h"

class UArcGISGeographicTransformationStep;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISGeographicTransformation;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
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
class ARCGISMAPSSDK_API UArcGISGeographicTransformation :
    public UArcGISDatumTransformation
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISGeographicTransformation")
    /// <summary>
    /// Create a single step transformation.
    /// </summary>
    /// <param name="step">A <see cref="Esri::GameEngine::Geometry::ArcGISGeographicTransformationStep">ArcGISGeographicTransformationStep</see> instance.</param>
    /// <since>1.0.0</since>
    static UArcGISGeographicTransformation* CreateArcGISGeographicTransformationWithStep(UArcGISGeographicTransformationStep* step);
    #pragma endregion Constructors
};