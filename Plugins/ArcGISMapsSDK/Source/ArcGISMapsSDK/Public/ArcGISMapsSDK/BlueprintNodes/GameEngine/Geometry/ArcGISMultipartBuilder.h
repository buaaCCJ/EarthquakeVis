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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGeometryBuilder.h"

#include "ArcGISMultipartBuilder.generated.h"

class UArcGISMutablePartCollection;
class UArcGISPoint;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISMultipartBuilder;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// The Multipart builder object is used to create a multipart geometry.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISMultipartBuilder :
    public UArcGISGeometryBuilder
{
    GENERATED_BODY()

public:
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMultipartBuilder")
    /// <summary>
    /// New parts for the multipart builder.
    /// </summary>
    /// <remarks>
    /// The collection of parts for the multipart builder. Changes to the collection are reflected in the multipart builder.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISMutablePartCollection">ArcGISMutablePartCollection</seealso>
    /// <since>1.0.0</since>
    UArcGISMutablePartCollection* GetParts();
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMultipartBuilder")
    /// <summary>
    /// New parts for the multipart builder.
    /// </summary>
    /// <remarks>
    /// The collection of parts for the multipart builder. Changes to the collection are reflected in the multipart builder.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISMutablePartCollection">ArcGISMutablePartCollection</seealso>
    /// <since>1.0.0</since>
    void SetParts(UArcGISMutablePartCollection* parts);
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMultipartBuilder")
    /// <summary>
    /// Adds a new point to the end of the last part of the multipart.
    /// </summary>
    /// <remarks>
    /// If there are no parts then an initial part is created and the point added to that.
    /// The point becomes the end point of a line segment in the part.
    /// </remarks>
    /// <param name="x">The x-coordinate of the point to add.</param>
    /// <param name="y">The y-coordinate of the point to add.</param>
    /// <returns>
    /// The point index of the new point in the last part.
    /// </returns>
    /// <since>1.0.0</since>
    int64 AddPointXY(double x, double y);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMultipartBuilder")
    /// <summary>
    /// Adds a new point to the end of the last part of the multipart.
    /// </summary>
    /// <remarks>
    /// If there are no parts then an initial part is created and the point added to that.
    /// The point becomes the end point of a line segment in the part.
    /// </remarks>
    /// <param name="x">The x-coordinate of the point to add.</param>
    /// <param name="y">The y-coordinate of the point to add.</param>
    /// <param name="z">The z-coordinate of the point to add.</param>
    /// <returns>
    /// the point index of the new point in the last part
    /// </returns>
    /// <since>1.0.0</since>
    int64 AddPointXYZ(double x, double y, double z);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISMultipartBuilder")
    /// <summary>
    /// Adds a new point to the end of the last part of the multipart.
    /// </summary>
    /// <remarks>
    /// If there are no parts then an initial part is created and the point added to that.
    /// The point becomes the end point of a line segment in the part.
    /// </remarks>
    /// <param name="point">The point to add</param>
    /// <returns>
    /// the point index of the new point in the last part
    /// </returns>
    /// <since>1.0.0</since>
    int64 AddPoint(UArcGISPoint* point);
    #pragma endregion Methods
};