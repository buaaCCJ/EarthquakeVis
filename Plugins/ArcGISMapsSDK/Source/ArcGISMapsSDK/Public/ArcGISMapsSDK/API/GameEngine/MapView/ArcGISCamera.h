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
class ArcGISPoint;
} // namespace Geometry

namespace MapView
{
/// <summary>
/// A camera on a view.
/// </summary>
/// <remarks>
/// An immutable object used to set a location of the camera on a view.
/// </remarks>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISCamera
{
public:
    #pragma region Constructors
    /// <summary>
    /// Create a camera object.
    /// </summary>
    /// <param name="locationPoint">A point geometry containing the location and altitude at which to place the camera.</param>
    /// <param name="heading">The heading of the camera.</param>
    /// <param name="pitch">The pitch of the camera. The value must be from 0 to 180 and represents the angle applied to the camera when rotating around its Y axis in the East, North, Up (ENU) ground reference frame. 0 is looking straight down towards the center of the earth, 180 looking straight up towards the sky. Negative pitches are not allowed and the values do not wrap around. If the behavior of a negative pitch is required, then the corresponding transformation with positive pitch can be set instead. For example if heading:0 pitch:-20 roll:0 is required then heading:180 pitch:20 roll:180 can be used instead.</param>
    /// <param name="roll">The roll of the camera.</param>
    /// <since>1.0.0</since>
    ArcGISCamera(const Geometry::ArcGISPoint& locationPoint, double heading, double pitch, double roll);
    #pragma endregion Constructors
    
    #pragma region Properties
    /// <summary>
    /// The heading of the camera.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::MapView::ArcGISCamera">ArcGISCamera</seealso>
    /// <since>1.0.0</since>
    double GetHeading() const;
    
    /// <summary>
    /// The location of the camera.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::MapView::ArcGISCamera">ArcGISCamera</seealso>
    /// <seealso cref="Esri::GameEngine::Geometry::ArcGISPoint">ArcGISPoint</seealso>
    /// <since>1.0.0</since>
    Geometry::ArcGISPoint GetLocation() const;
    
    /// <summary>
    /// The pitch of the camera.
    /// </summary>
    /// <remarks>
    /// The pitch value must be from 0 to 180 and represents the angle applied to the
    /// camera when rotating around its Y axis in the East, North, Up (ENU) ground reference frame. 0 is looking straight
    /// down towards the center of the earth, 180 looking straight up towards the sky. Negative
    /// pitches are not allowed and the values do not wrap around. If the behavior of a negative pitch is required, then the
    /// corresponding transformation with positive pitch can be set instead. For example if heading:0 pitch:-20 roll:0 is
    /// required then heading:180 pitch:20 roll:180 can be used instead.
    /// </remarks>
    /// <seealso cref="Esri::GameEngine::MapView::ArcGISCamera">ArcGISCamera</seealso>
    /// <since>1.0.0</since>
    double GetPitch() const;
    
    /// <summary>
    /// The roll of the camera.
    /// </summary>
    /// <seealso cref="Esri::GameEngine::MapView::ArcGISCamera">ArcGISCamera</seealso>
    /// <since>1.0.0</since>
    double GetRoll() const;
    #pragma endregion Properties
    
    #pragma region Methods
    /// <summary>
    /// Creates a copy of the camera with the altitude adjusted.
    /// </summary>
    /// <param name="deltaAltitude">The altitude delta to apply to the output camera.</param>
    /// <returns>
    /// A copy of the camera with an elevation delta adjusted by the parameter delta_altitude.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::MapView::ArcGISCamera">ArcGISCamera</seealso>
    /// <since>1.0.0</since>
    ArcGISCamera Elevate(double deltaAltitude) const;
    
    /// <summary>
    /// Tests if this object is equal to a second <see cref="Esri::GameEngine::MapView::ArcGISCamera">ArcGISCamera</see> object.
    /// </summary>
    /// <param name="otherCamera">The other camera object.</param>
    /// <returns>
    /// True if the comparison succeeds and the objects are equal, false otherwise.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::MapView::ArcGISCamera">ArcGISCamera</seealso>
    /// <since>1.0.0</since>
    bool Equals(const ArcGISCamera& otherCamera) const;
    
    /// <summary>
    /// Creates a copy of the camera with the location changed.
    /// </summary>
    /// <param name="location">The location to move the output camera to.</param>
    /// <returns>
    /// A copy of the camera with the location changed.
    /// </returns>
    /// <seealso cref="Esri::GameEngine::MapView::ArcGISCamera">ArcGISCamera</seealso>
    /// <since>1.0.0</since>
    ArcGISCamera MoveTo(const Geometry::ArcGISPoint& location) const;
    
    /// <summary>
    /// Creates a copy of the camera with a change in pitch, heading and roll to the given angles in degrees
    /// </summary>
    /// <param name="heading">The angle in degrees to which the output camera heading will be rotated</param>
    /// <param name="pitch">The angle in degrees to which the output camera pitch will be rotated. The value must be from 0 to 180 and represents the angle applied to the camera when rotating around its Y axis in the East, North, Up (ENU) ground reference frame. 0 is looking straight down towards the center of the earth, 180 looking straight up towards the sky. Negative pitches are not allowed and the values do not wrap around. If the behavior of a negative pitch is required, then the corresponding transformation with positive pitch can be set instead. For example if heading:0 pitch:-20 roll:0 is required then heading:180 pitch:20 roll:180 can be used instead.</param>
    /// <param name="roll">The angle in degrees to which the output camera roll will be rotated</param>
    /// <returns>
    /// A copy of the camera with the position moved
    /// </returns>
    /// <seealso cref="Esri::GameEngine::MapView::ArcGISCamera">ArcGISCamera</seealso>
    /// <since>1.0.0</since>
    ArcGISCamera RotateTo(double heading, double pitch, double roll) const;
    #pragma endregion Methods

public:
    #pragma region Special Members
    explicit ArcGISCamera(void* handle);
    ArcGISCamera(const ArcGISCamera&) = delete;
    ArcGISCamera(ArcGISCamera&& other) noexcept;
    ArcGISCamera() = default;
    ~ArcGISCamera();
    
    ArcGISCamera& operator=(const ArcGISCamera&) = delete;
    ArcGISCamera& operator=(ArcGISCamera&& other) noexcept;
    operator bool() const noexcept;
    
    void* GetHandle() const;
    void SetHandle(void* handle);
    #pragma endregion Special Members

protected:
    void* m_handle{ nullptr };
};
} // namespace MapView
} // namespace GameEngine
} // namespace Esri