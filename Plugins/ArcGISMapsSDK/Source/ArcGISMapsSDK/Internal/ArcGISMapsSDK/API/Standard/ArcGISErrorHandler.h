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

#include "ArcGISMapsSDK/API/GameEngine/ArcGISRuntimeEnvironmentErrorEvent.h"

namespace Esri
{
namespace Standard
{
struct ArcGISErrorHandler
{
    /// <summary>
    /// The function pointer which will be called when an error occurs. <see cref="Esri::GameEngine::ArcGISRuntimeEnvironmentErrorEvent">ArcGISRuntimeEnvironmentErrorEvent</see>
    /// </summary>
    /// <since>1.0.0</since>
    GameEngine::ArcGISRuntimeEnvironmentErrorEvent Handler;
    
    /// <summary>
    /// This is any pointer information you want to have when a error occurs.
    /// </summary>
    /// <since>1.0.0</since>
    void* UserData;
};
} // namespace Standard
} // namespace Esri