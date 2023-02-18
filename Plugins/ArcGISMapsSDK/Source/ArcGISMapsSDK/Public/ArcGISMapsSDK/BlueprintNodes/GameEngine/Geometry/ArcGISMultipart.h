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

#include "ArcGISMultipart.generated.h"

class UArcGISImmutablePartCollection;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISMultipart;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// Defines common members for polyline and polygon multipart geometries.
/// </summary>
/// <remarks>
/// Multipart geometries are based upon the parent <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see> class. The geometry
/// class is immutable which means that you cannot change its shape once it is created.
/// If you need to modify a multipart once it has been created, use the <see cref="Esri::GameEngine::Geometry::ArcGISMultipartBuilder">ArcGISMultipartBuilder</see>
/// class instead. The <see cref="Esri::GameEngine::Geometry::ArcGISMultipartBuilder.toGeometry">ArcGISMultipartBuilder.toGeometry</see> method provides you with
/// the base geometry object.
/// 
/// A multipart geometry is comprised of a collection of shapes (of the same type) that
/// is managed as a single geometry. A classic example is a set of islands that represent
/// a single country or state. The individual island shapes are distinct, but ArcGIS considers
/// it a single geometry.
/// 
/// <see cref="Esri::GameEngine::Geometry::ArcGISPolygon">ArcGISPolygon</see> and <see cref="Esri::GameEngine::Geometry::ArcGISPolyline">ArcGISPolyline</see> inherit from multipart, which in turn inherits from
/// <see cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</see>. Multipart provides access to the geometry's <see cref="Esri::GameEngine::Geometry::ArcGISImmutablePartCollection">ArcGISImmutablePartCollection</see>
/// via the <see cref="Esri::GameEngine::Geometry::ArcGISMultipart.parts">ArcGISMultipart.parts</see> property. Each <see cref="Esri::GameEngine::Geometry::ArcGISImmutablePart">ArcGISImmutablePart</see> in the collection is a
/// collection of <see cref="Esri::GameEngine::Geometry::ArcGISSegment">ArcGISSegment</see> objects. You can iterate through the segments or points in
/// each part.
/// </remarks>
/// <seealso cref="Esri::GameEngine::Geometry::ArcGISGeometry">ArcGISGeometry</seealso>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISMultipart :
    public UArcGISGeometry
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMultipart")
    /// <summary>
    /// The parts for the multipart.
    /// </summary>
    /// <remarks>
    /// This is a copy and the any changes must be set.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISMutablePartCollection">ArcGISMutablePartCollection</seealso>
    /// <since>1.0.0</since>
    UArcGISImmutablePartCollection* GetParts();
    #pragma endregion Properties
};