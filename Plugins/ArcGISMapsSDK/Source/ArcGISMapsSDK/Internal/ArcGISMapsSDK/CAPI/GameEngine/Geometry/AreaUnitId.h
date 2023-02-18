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

typedef enum RT_AreaUnitId
{
    RT_AreaUnitId_other = 0,
    RT_AreaUnitId_acres = 109402,
    RT_AreaUnitId_hectares = 109401,
    RT_AreaUnitId_squareCentimeters = 109451,
    RT_AreaUnitId_squareDecimeters = 109450,
    RT_AreaUnitId_squareFeet = 109405,
    RT_AreaUnitId_squareKilometers = 109414,
    RT_AreaUnitId_squareMeters = 109404,
    RT_AreaUnitId_squareMillimeters = 109452,
    RT_AreaUnitId_squareMiles = 109439,
    RT_AreaUnitId_squareYards = 109442
} RT_AreaUnitId;

#ifdef __cplusplus
} // extern "C"
#endif