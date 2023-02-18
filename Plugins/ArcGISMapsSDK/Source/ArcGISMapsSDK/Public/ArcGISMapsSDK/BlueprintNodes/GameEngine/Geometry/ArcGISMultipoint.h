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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometry.h"

#include "ArcGISMultipoint.generated.h"

class UArcGISImmutablePointCollection;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISMultipoint;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// An ordered collection of points that can be managed as a single geometry.
/// </summary>
/// <remarks>
/// <see cref="Esri::GameEngine::Geometry::ArcGISMultipoint">ArcGISMultipoint</see> geometries represent an ordered collection of points. They can be used as 
/// the geometry of features and graphics, or as input or output for spatial operations. For 
/// features that consist of a very large number of points that share the same set of attribute 
/// values, multipoints may be more efficient to store and analyze in a geodatabase compared to 
/// using multiple point features.
/// 
/// A <see cref="Esri::GameEngine::Geometry::ArcGISMultipoint">ArcGISMultipoint</see> is composed of a single read-only collection of <see cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</see>. Use <see cref="Esri::GameEngine::Geometry::ArcGISMultipointBuilder">ArcGISMultipointBuilder</see> 
/// to build a multipoint one point at a time or to modify an existing <see cref="Esri::GameEngine::Geometry::ArcGISMultipoint">ArcGISMultipoint</see>.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISMultipoint :
    public UArcGISGeometry
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMultipoint")
    /// <summary>
    /// The read-only collection of points for the multipoint.
    /// </summary>
    /// <remarks>
    /// Use <see cref="Esri::GameEngine::Geometry::ArcGISMultipointBuilder">ArcGISMultipointBuilder</see> to build a multipoint one point at a time or to modify 
    /// the points that compose an existing <see cref="Esri::GameEngine::Geometry::ArcGISMultipoint">ArcGISMultipoint</see>.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISImmutablePointCollection* GetPoints();
    #pragma endregion Properties
};