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
namespace Math
{
struct ArcGISOrientedBoundingBox
{
    /// <summary>
    /// X coordinate of the center of the oriented bounding box
    /// </summary>
    /// <since>1.0.0</since>
    double CenterX;
    
    /// <summary>
    /// Y coordinate of the center of the oriented bounding box
    /// </summary>
    /// <since>1.0.0</since>
    double CenterY;
    
    /// <summary>
    /// Z coordinate of the center of the oriented bounding box
    /// </summary>
    /// <since>1.0.0</since>
    double CenterZ;
    
    /// <summary>
    /// Half-size of the oriented bounding box along the local X axis
    /// </summary>
    /// <since>1.0.0</since>
    float ExtentX;
    
    /// <summary>
    /// Half-size of the oriented bounding box along the local Y axis
    /// </summary>
    /// <since>1.0.0</since>
    float ExtentY;
    
    /// <summary>
    /// Half-size of the oriented bounding box along the local Z axis
    /// </summary>
    /// <since>1.0.0</since>
    float ExtentZ;
    
    /// <summary>
    /// Orientation of the box - quaternion component X
    /// </summary>
    /// <since>1.0.0</since>
    double OrientationX;
    
    /// <summary>
    /// Orientation of the box - quaternion component Y
    /// </summary>
    /// <since>1.0.0</since>
    double OrientationY;
    
    /// <summary>
    /// Orientation of the box - quaternion component Z
    /// </summary>
    /// <since>1.0.0</since>
    double OrientationZ;
    
    /// <summary>
    /// Orientation of the box - quaternion component W
    /// </summary>
    /// <since>1.0.0</since>
    double OrientationW;
};
} // namespace Math
} // namespace GameEngine
} // namespace Esri