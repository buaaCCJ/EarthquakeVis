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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISCoordinateFormatter.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGARSConversionMode.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLatitudeLongitudeFormat.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMGRSConversionMode.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISUTMConversionMode.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/CoordinateFormatter.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISPoint ArcGISCoordinateFormatter::FromGARS(const FString& coordinates, const ArcGISSpatialReference& spatialReference, ArcGISGARSConversionMode GARSConversionMode)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_CoordinateFormatter_fromGARS(TCHAR_TO_ANSI(*coordinates), localSpatialReference, static_cast<RT_GARSConversionMode>(GARSConversionMode), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISCoordinateFormatter::FromGeoRef(const FString& coordinates, const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_CoordinateFormatter_fromGeoRef(TCHAR_TO_ANSI(*coordinates), localSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISCoordinateFormatter::FromLatitudeLongitude(const FString& coordinates, const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_CoordinateFormatter_fromLatitudeLongitude(TCHAR_TO_ANSI(*coordinates), localSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISCoordinateFormatter::FromMGRS(const FString& coordinates, const ArcGISSpatialReference& spatialReference, ArcGISMGRSConversionMode MGRSConversionMode)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_CoordinateFormatter_fromMGRS(TCHAR_TO_ANSI(*coordinates), localSpatialReference, static_cast<RT_MGRSConversionMode>(MGRSConversionMode), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISCoordinateFormatter::FromUSNG(const FString& coordinates, const ArcGISSpatialReference& spatialReference)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_CoordinateFormatter_fromUSNG(TCHAR_TO_ANSI(*coordinates), localSpatialReference, &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

ArcGISPoint ArcGISCoordinateFormatter::FromUTM(const FString& coordinates, const ArcGISSpatialReference& spatialReference, ArcGISUTMConversionMode UTMConversionMode)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localSpatialReference = static_cast<const RT_SpatialReferenceHandle>(spatialReference.GetHandle());
    
    auto localResult = RT_CoordinateFormatter_fromUTM(TCHAR_TO_ANSI(*coordinates), localSpatialReference, static_cast<RT_UTMConversionMode>(UTMConversionMode), &errorHandler);
    
    auto localLocalResult = ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

FString ArcGISCoordinateFormatter::ToGARS(const ArcGISPoint& point)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_CoordinateFormatter_toGARS(localPoint, &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISCoordinateFormatter::ToGeoRef(const ArcGISPoint& point, int32_t precision)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_CoordinateFormatter_toGeoRef(localPoint, precision, &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISCoordinateFormatter::ToLatitudeLongitude(const ArcGISPoint& point, ArcGISLatitudeLongitudeFormat format, int32_t decimalPlaces)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_CoordinateFormatter_toLatitudeLongitude(localPoint, static_cast<RT_LatitudeLongitudeFormat>(format), decimalPlaces, &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISCoordinateFormatter::ToMGRS(const ArcGISPoint& point, ArcGISMGRSConversionMode MGRSConversionMode, int32_t precision, bool addSpaces)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_CoordinateFormatter_toMGRS(localPoint, static_cast<RT_MGRSConversionMode>(MGRSConversionMode), precision, addSpaces, &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISCoordinateFormatter::ToUSNG(const ArcGISPoint& point, int32_t precision, bool addSpaces)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_CoordinateFormatter_toUSNG(localPoint, precision, addSpaces, &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISCoordinateFormatter::ToUTM(const ArcGISPoint& point, ArcGISUTMConversionMode UTMConversionMode, bool addSpaces)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localPoint = static_cast<const RT_PointHandle>(point.GetHandle());
    
    auto localResult = RT_CoordinateFormatter_toUTM(localPoint, static_cast<RT_UTMConversionMode>(UTMConversionMode), addSpaces, &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri