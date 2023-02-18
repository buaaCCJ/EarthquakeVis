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

typedef enum RT_BasemapStyle
{
    RT_BasemapStyle_arcGISImagery = 0,
    RT_BasemapStyle_arcGISImageryStandard = 1,
    RT_BasemapStyle_arcGISImageryLabels = 2,
    RT_BasemapStyle_arcGISLightGray = 3,
    RT_BasemapStyle_arcGISLightGrayBase = 4,
    RT_BasemapStyle_arcGISLightGrayLabels = 5,
    RT_BasemapStyle_arcGISDarkGray = 6,
    RT_BasemapStyle_arcGISDarkGrayBase = 7,
    RT_BasemapStyle_arcGISDarkGrayLabels = 8,
    RT_BasemapStyle_arcGISNavigation = 9,
    RT_BasemapStyle_arcGISNavigationNight = 10,
    RT_BasemapStyle_arcGISStreets = 11,
    RT_BasemapStyle_arcGISStreetsNight = 12,
    RT_BasemapStyle_arcGISStreetsRelief = 13,
    RT_BasemapStyle_arcGISTopographic = 14,
    RT_BasemapStyle_arcGISOceans = 15,
    RT_BasemapStyle_arcGISOceansBase = 16,
    RT_BasemapStyle_arcGISOceansLabels = 17,
    RT_BasemapStyle_arcGISTerrain = 18,
    RT_BasemapStyle_arcGISTerrainBase = 19,
    RT_BasemapStyle_arcGISTerrainDetail = 20,
    RT_BasemapStyle_arcGISCommunity = 21,
    RT_BasemapStyle_arcGISChartedTerritory = 22,
    RT_BasemapStyle_arcGISColoredPencil = 23,
    RT_BasemapStyle_arcGISNova = 24,
    RT_BasemapStyle_arcGISModernAntique = 25,
    RT_BasemapStyle_arcGISMidcentury = 26,
    RT_BasemapStyle_arcGISNewspaper = 27,
    RT_BasemapStyle_arcGISHillshadeLight = 28,
    RT_BasemapStyle_arcGISHillshadeDark = 29,
    RT_BasemapStyle_arcGISStreetsReliefBase = 30,
    RT_BasemapStyle_arcGISTopographicBase = 31,
    RT_BasemapStyle_arcGISChartedTerritoryBase = 32,
    RT_BasemapStyle_arcGISModernAntiqueBase = 33,
    RT_BasemapStyle_OSMStandard = 101,
    RT_BasemapStyle_OSMStandardRelief = 102,
    RT_BasemapStyle_OSMStandardReliefBase = 103,
    RT_BasemapStyle_OSMStreets = 104,
    RT_BasemapStyle_OSMStreetsRelief = 105,
    RT_BasemapStyle_OSMLightGray = 106,
    RT_BasemapStyle_OSMLightGrayBase = 107,
    RT_BasemapStyle_OSMLightGrayLabels = 108,
    RT_BasemapStyle_OSMDarkGray = 109,
    RT_BasemapStyle_OSMDarkGrayBase = 110,
    RT_BasemapStyle_OSMDarkGrayLabels = 111,
    RT_BasemapStyle_OSMStreetsReliefBase = 112
} RT_BasemapStyle;

#ifdef __cplusplus
} // extern "C"
#endif