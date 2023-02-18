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

#include "ArcGISMapsSDK/CAPI/GameEngine/Math/DoubleVector4.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/RCQ/MaterialVectorProperty.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct RT_SetRenderableMaterialVectorPropertyCommandParameters
{
    uint32_t renderableId;
    RT_MaterialVectorProperty materialVectorProperty;
    RT_DoubleVector4 value;
} RT_SetRenderableMaterialVectorPropertyCommandParameters;

#ifdef __cplusplus
} // extern "C"
#endif