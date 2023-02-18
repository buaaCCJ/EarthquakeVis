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

#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpheroidData.h"

#include "ArcGISSpatialReference.generated.h"

class UArcGISUnit;
class UArcGISLinearUnit;
class UArcGISPoint;

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
class ArcGISSpatialReference;
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri

UCLASS(BlueprintType, Blueprintable)
/// <summary>
/// A spatial reference object.
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API UArcGISSpatialReference :
    public UObject
{
    GENERATED_BODY()

public:
    #pragma region Constructors
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// Creates a spatial reference based on WKID.
    /// </summary>
    /// <remarks>
    /// The method will create a spatial reference that has only horizontal coordinate system and does not have vertical
    /// coordinate system associated with it.
    /// </remarks>
    /// <param name="WKID">The well-known ID of the horizontal coordinate system. Must be a positive value.</param>
    /// <since>1.0.0</since>
    static UArcGISSpatialReference* CreateArcGISSpatialReference(int32 WKID);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// Creates a spatial reference based on WKID for the horizontal coordinate system and vertical coordinate system.
    /// </summary>
    /// <remarks>
    /// The method creates a spatial reference that has both horizontal and vertical coordinate systems.
    /// When the vertical WKID is 0, the method is equivalent to calling <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference.SpatialReference">ArcGISSpatialReference.SpatialReference</see>,
    /// and does not define a vertical coordinate system part.
    /// </remarks>
    /// <param name="WKID">The well-known ID of the horizontal coordinate system. Must be a positive value.</param>
    /// <param name="verticalWKID">The well-known ID of the vertical  coordinate system. Must be a non negative value.</param>
    /// <since>1.0.0</since>
    static UArcGISSpatialReference* CreateArcGISSpatialReferenceVerticalWKID(int32 WKID, int32 verticalWKID);
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// Creates a spatial reference based on well-known text.
    /// </summary>
    /// <param name="wkText">The well-known text of the spatial reference to create.</param>
    /// <since>1.0.0</since>
    static UArcGISSpatialReference* CreateArcGISSpatialReferenceFromWKText(FString wkText);
    #pragma endregion Constructors
    
    #pragma region Properties
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// If the given spatial reference is a projected coordinate system, then this returns the geographic coordinate system of that system.
    /// </summary>
    /// <remarks>
    /// If the spatial reference is a projected coordinate system, then a spatial reference object representing the underlying geographic
    /// coordinate system is returned. Every projected coordinate system has an underlying geographic coordinate system. If the
    /// spatial reference is a geographic coordinate system, then a reference to itself is returned.
    /// If the spatial reference is a local spatial reference, a null is returned with an error.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISSpatialReference* GetBaseGeographic();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// True if spatial reference has a vertical coordinate system set; false otherwise.
    /// </summary>
    /// <remarks>
    /// A spatial reference can optionally include a definition for a vertical coordinate system (VCS), which
    /// can be used to interpret the z-values of a geometry. A VCS defines linear units of measure, the origin of
    /// z-values, and whether z-values are "positive up" (representing heights above a surface) or "positive down"
    /// (indicating that values are depths below a surface).
    /// 
    /// A <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> may have a VCS set, for example by calling the
    /// <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference.SpatialReference">ArcGISSpatialReference.SpatialReference</see> constructor. <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference.verticalWKID">ArcGISSpatialReference.verticalWKID</see>,
    /// <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference.WKText">ArcGISSpatialReference.WKText</see>, and <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference.verticalUnit">ArcGISSpatialReference.verticalUnit</see> provide more information about the
    /// specific VCS set on this instance.
    /// 
    /// VCSs are used when projecting geometries using a <see cref="Esri::GameEngine::Geometry::ArcGISHorizontalVerticalTransformation">ArcGISHorizontalVerticalTransformation</see>.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference.verticalWKID">ArcGISSpatialReference.verticalWKID</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference.verticalUnit">ArcGISSpatialReference.verticalUnit</seealso>
    /// <since>1.0.0</since>
    bool GetHasVertical();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// True if spatial reference is a Geographic Coordinate System.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsGeographic();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// True if coordinate system is horizontally pannable.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsPannable();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// True if spatial reference is a Projected Coordinate System.
    /// </summary>
    /// <since>1.0.0</since>
    bool GetIsProjected();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// The spheroid data for the spatial reference
    /// </summary>
    /// <remarks>
    /// The spheroid data for the spatial reference.
    /// </remarks>
    /// <since>1.0.0</since>
    FArcGISSpheroidData GetSpheroidData();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// The unit of measure for the horizontal coordinate system of this spatial reference.
    /// </summary>
    /// <since>1.0.0</since>
    UArcGISUnit* GetUnit();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// The unit of measure for the vertical coordinate system of this spatial reference.
    /// </summary>
    /// <remarks>
    /// Is null if <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference.hasVertical">ArcGISSpatialReference.hasVertical</see> is false.
    /// </remarks>
    /// <since>1.0.0</since>
    UArcGISLinearUnit* GetVerticalUnit();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// The well-known ID for the vertical coordinate system (VCS), or 0 if the spatial reference
    /// has no VCS or has a custom VCS.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISSpatialReference.SpatialReference">ArcGISSpatialReference.SpatialReference</seealso>
    /// <since>1.0.0</since>
    int32 GetVerticalWKID();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// The well-known ID for the horizontal coordinate system, or 0 if the spatial reference
    /// has a custom horizontal coordinate system.
    /// </summary>
    /// <since>1.0.0</since>
    int32 GetWKID();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// The well-known text for the horizontal and vertical coordinate system.
    /// </summary>
    /// <since>1.0.0</since>
    FString GetWKText();
    #pragma endregion Properties
    
    #pragma region Methods
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// Tests if this object is equal to a second <see cref="Esri::GameEngine::Geometry::ArcGISSpatialReference">ArcGISSpatialReference</see> object.
    /// </summary>
    /// <param name="right">The 2nd spatial reference to check to see if equal to the 1st.</param>
    /// <returns>
    /// True if the comparison succeeds and the objects are equal, false otherwise.
    /// </returns>
    /// <since>1.0.0</since>
    bool Equals(UArcGISSpatialReference* right) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// Calculate the grid convergence for a spatial reference at a given point.
    /// </summary>
    /// <remarks>
    /// The grid convergence is the angle between True North and Grid North
    /// at a point on a map. The grid convergence can be used to convert a
    /// horizontal direction expressed as an azimuth in a geographic
    /// coordinate system (relative to True North) to a direction expressed
    /// as a bearing in a projected coordinate system (relative to Grid
    /// North), and vice versa.
    /// 
    /// Sign convention
    /// 
    /// The grid convergence returned by this method is positive when Grid
    /// North lies east of True North. The following formula demonstrates
    /// how to obtain a bearing (b) from an azimuth (a) using the grid
    /// convergence (c) returned by this method:
    /// 
    /// b = a - c
    /// 
    /// This sign convention is sometimes named the Gauss-Bomford convention.
    /// 
    /// Other notes:
    /// * Returns 0 if the spatial reference is a geographic coordinate system
    /// * Returns NAN if the point is outside the projection's horizon or on error
    /// * If the point has no spatial reference, it is assumed to be in the
    ///   given spatial reference
    /// * If the point's spatial reference differs from the spatial
    ///   reference given, its location is transformed automatically to
    ///   the given spatial reference
    /// </remarks>
    /// <param name="point">The point</param>
    /// <returns>
    /// The grid convergence in degrees.
    /// </returns>
    /// <since>1.0.0</since>
    double GetConvergenceAngle(UArcGISPoint* point) const;
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// Creates a spatial reference based on web Mercator.
    /// </summary>
    /// <remarks>
    /// The method creates a web Mercator spatial reference.
    /// </remarks>
    /// <returns>
    /// A spatial reference. This is passed to spatial reference functions.
    /// null if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    static UArcGISSpatialReference* WebMercator();
    
    UFUNCTION(BlueprintCallable, Category = "ArcGISMapsSDK|ArcGISSpatialReference")
    /// <summary>
    /// Creates a spatial reference based on WGS84.
    /// </summary>
    /// <remarks>
    /// The method creates a WGS84 spatial reference.
    /// </remarks>
    /// <returns>
    /// A spatial reference. This is passed to spatial reference functions.
    /// null if an error occurs.
    /// </returns>
    /// <since>1.0.0</since>
    static UArcGISSpatialReference* WGS84();
    #pragma endregion Methods

public:
    TSharedPtr<Esri::GameEngine::Geometry::ArcGISSpatialReference> APIObject;
};