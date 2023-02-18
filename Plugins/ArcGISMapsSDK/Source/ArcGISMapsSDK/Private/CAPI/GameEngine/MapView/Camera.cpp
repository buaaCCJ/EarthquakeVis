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

#if PLATFORM_MAC || PLATFORM_HOLOLENS
#include "ArcGISMapsSDK/CAPI/GameEngine/MapView/Camera.h"
#include "ArcGISMapsSDK/CAPI/Platform.h"

void RT_Camera_destroy(RT_CameraHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef void (*RT_Camera_destroy_def)(RT_CameraHandle, const RT_ErrorHandler*);
    static auto RT_Camera_destroy_func = reinterpret_cast<RT_Camera_destroy_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Camera_destroy")));
    
    RT_Camera_destroy_func(thisHandle, errorHandler);
}

RT_CameraHandle RT_Camera_createWithLocationHeadingPitchRoll(const RT_PointHandle locationPoint, double heading, double pitch, double roll, const RT_ErrorHandler* errorHandler)
{
    typedef RT_CameraHandle (*RT_Camera_createWithLocationHeadingPitchRoll_def)(const RT_PointHandle, double, double, double, const RT_ErrorHandler*);
    static auto RT_Camera_createWithLocationHeadingPitchRoll_func = reinterpret_cast<RT_Camera_createWithLocationHeadingPitchRoll_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Camera_createWithLocationHeadingPitchRoll")));
    
    return RT_Camera_createWithLocationHeadingPitchRoll_func(locationPoint, heading, pitch, roll, errorHandler);
}

double RT_Camera_getHeading(const RT_CameraHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Camera_getHeading_def)(const RT_CameraHandle, const RT_ErrorHandler*);
    static auto RT_Camera_getHeading_func = reinterpret_cast<RT_Camera_getHeading_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Camera_getHeading")));
    
    return RT_Camera_getHeading_func(thisHandle, errorHandler);
}

RT_PointHandle RT_Camera_getLocation(const RT_CameraHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef RT_PointHandle (*RT_Camera_getLocation_def)(const RT_CameraHandle, const RT_ErrorHandler*);
    static auto RT_Camera_getLocation_func = reinterpret_cast<RT_Camera_getLocation_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Camera_getLocation")));
    
    return RT_Camera_getLocation_func(thisHandle, errorHandler);
}

double RT_Camera_getPitch(const RT_CameraHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Camera_getPitch_def)(const RT_CameraHandle, const RT_ErrorHandler*);
    static auto RT_Camera_getPitch_func = reinterpret_cast<RT_Camera_getPitch_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Camera_getPitch")));
    
    return RT_Camera_getPitch_func(thisHandle, errorHandler);
}

double RT_Camera_getRoll(const RT_CameraHandle thisHandle, const RT_ErrorHandler* errorHandler)
{
    typedef double (*RT_Camera_getRoll_def)(const RT_CameraHandle, const RT_ErrorHandler*);
    static auto RT_Camera_getRoll_func = reinterpret_cast<RT_Camera_getRoll_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Camera_getRoll")));
    
    return RT_Camera_getRoll_func(thisHandle, errorHandler);
}

RT_CameraHandle RT_Camera_elevate(const RT_CameraHandle thisHandle, double deltaAltitude, const RT_ErrorHandler* errorHandler)
{
    typedef RT_CameraHandle (*RT_Camera_elevate_def)(const RT_CameraHandle, double, const RT_ErrorHandler*);
    static auto RT_Camera_elevate_func = reinterpret_cast<RT_Camera_elevate_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Camera_elevate")));
    
    return RT_Camera_elevate_func(thisHandle, deltaAltitude, errorHandler);
}

bool RT_Camera_equals(const RT_CameraHandle thisHandle, const RT_CameraHandle otherCamera, const RT_ErrorHandler* errorHandler)
{
    typedef bool (*RT_Camera_equals_def)(const RT_CameraHandle, const RT_CameraHandle, const RT_ErrorHandler*);
    static auto RT_Camera_equals_func = reinterpret_cast<RT_Camera_equals_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Camera_equals")));
    
    return RT_Camera_equals_func(thisHandle, otherCamera, errorHandler);
}

RT_CameraHandle RT_Camera_moveTo(const RT_CameraHandle thisHandle, const RT_PointHandle location, const RT_ErrorHandler* errorHandler)
{
    typedef RT_CameraHandle (*RT_Camera_moveTo_def)(const RT_CameraHandle, const RT_PointHandle, const RT_ErrorHandler*);
    static auto RT_Camera_moveTo_func = reinterpret_cast<RT_Camera_moveTo_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Camera_moveTo")));
    
    return RT_Camera_moveTo_func(thisHandle, location, errorHandler);
}

RT_CameraHandle RT_Camera_rotateTo(const RT_CameraHandle thisHandle, double heading, double pitch, double roll, const RT_ErrorHandler* errorHandler)
{
    typedef RT_CameraHandle (*RT_Camera_rotateTo_def)(const RT_CameraHandle, double, double, double, const RT_ErrorHandler*);
    static auto RT_Camera_rotateTo_func = reinterpret_cast<RT_Camera_rotateTo_def>(FPlatformProcess::GetDllExport(GetRTCDLLHandle(), TEXT("RT_Camera_rotateTo")));
    
    return RT_Camera_rotateTo_func(thisHandle, heading, pitch, roll, errorHandler);
}
#endif