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

#include "ArcGISMapsSDK/CAPI/Platform.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum RT_RenderCommandType
{
    RT_RenderCommandType_createRenderTarget = 1,
    RT_RenderCommandType_createTexture = 2,
    RT_RenderCommandType_createRenderable = 3,
    RT_RenderCommandType_destroyRenderTarget = 5,
    RT_RenderCommandType_destroyTexture = 6,
    RT_RenderCommandType_destroyRenderable = 7,
    RT_RenderCommandType_multipleCompose = 8,
    RT_RenderCommandType_copy = 10,
    RT_RenderCommandType_generateNormalTexture = 11,
    RT_RenderCommandType_setTexturePixelData = 12,
    RT_RenderCommandType_setRenderableMaterialScalarProperty = 13,
    RT_RenderCommandType_setRenderableMaterialVectorProperty = 14,
    RT_RenderCommandType_setRenderableMaterialRenderTargetProperty = 15,
    RT_RenderCommandType_setRenderableMaterialTextureProperty = 16,
    RT_RenderCommandType_setRenderableVisible = 18,
    RT_RenderCommandType_setRenderableMesh = 20,
    RT_RenderCommandType_setRenderablePivot = 22,
    RT_RenderCommandType_setRenderableMaterialNamedTextureProperty = 23,
    RT_RenderCommandType_commandGroupBegin = 24,
    RT_RenderCommandType_commandGroupEnd = 25
} RT_RenderCommandType;

#ifdef __cplusplus
} // extern "C"
#endif