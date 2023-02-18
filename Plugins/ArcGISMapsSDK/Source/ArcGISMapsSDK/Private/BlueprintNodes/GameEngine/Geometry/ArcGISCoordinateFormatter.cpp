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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISCoordinateFormatter.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGARSConversionMode.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISLatitudeLongitudeFormat.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISMGRSConversionMode.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISUTMConversionMode.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISCoordinateFormatter.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISGARSConversionMode.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISLatitudeLongitudeFormat.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISMGRSConversionMode.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/BlueprintNodes/GameEngine/Geometry/ArcGISUTMConversionMode.h"

UArcGISPoint* UArcGISCoordinateFormatter::FromGARS(FString coordinates, UArcGISSpatialReference* spatialReference, EArcGISGARSConversionMode::Type GARSConversionMode)
{
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISCoordinateFormatter::FromGARS(coordinates, spatialReference ? *spatialReference->APIObject : nullSpatialReference, static_cast<Esri::GameEngine::Geometry::ArcGISGARSConversionMode>(GARSConversionMode));
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPoint* UArcGISCoordinateFormatter::FromGeoRef(FString coordinates, UArcGISSpatialReference* spatialReference)
{
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISCoordinateFormatter::FromGeoRef(coordinates, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPoint* UArcGISCoordinateFormatter::FromLatitudeLongitude(FString coordinates, UArcGISSpatialReference* spatialReference)
{
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISCoordinateFormatter::FromLatitudeLongitude(coordinates, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPoint* UArcGISCoordinateFormatter::FromMGRS(FString coordinates, UArcGISSpatialReference* spatialReference, EArcGISMGRSConversionMode::Type MGRSConversionMode)
{
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISCoordinateFormatter::FromMGRS(coordinates, spatialReference ? *spatialReference->APIObject : nullSpatialReference, static_cast<Esri::GameEngine::Geometry::ArcGISMGRSConversionMode>(MGRSConversionMode));
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPoint* UArcGISCoordinateFormatter::FromUSNG(FString coordinates, UArcGISSpatialReference* spatialReference)
{
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISCoordinateFormatter::FromUSNG(coordinates, spatialReference ? *spatialReference->APIObject : nullSpatialReference);
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

UArcGISPoint* UArcGISCoordinateFormatter::FromUTM(FString coordinates, UArcGISSpatialReference* spatialReference, EArcGISUTMConversionMode::Type UTMConversionMode)
{
    auto nullSpatialReference = Esri::GameEngine::Geometry::ArcGISSpatialReference{};
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISCoordinateFormatter::FromUTM(coordinates, spatialReference ? *spatialReference->APIObject : nullSpatialReference, static_cast<Esri::GameEngine::Geometry::ArcGISUTMConversionMode>(UTMConversionMode));
    
    auto localLocalResult = NewObject<UArcGISPoint>();
    
    localLocalResult->APIObject = ::MakeShared<Esri::GameEngine::Geometry::ArcGISPoint>(std::move(localResult));
    
    return localLocalResult;
}

FString UArcGISCoordinateFormatter::ToGARS(UArcGISPoint* point)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISCoordinateFormatter::ToGARS(point ? *derivedPointAPIObject : nullPoint);
    
    return localResult;
}

FString UArcGISCoordinateFormatter::ToGeoRef(UArcGISPoint* point, int32 precision)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISCoordinateFormatter::ToGeoRef(point ? *derivedPointAPIObject : nullPoint, precision);
    
    return localResult;
}

FString UArcGISCoordinateFormatter::ToLatitudeLongitude(UArcGISPoint* point, EArcGISLatitudeLongitudeFormat::Type format, int32 decimalPlaces)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISCoordinateFormatter::ToLatitudeLongitude(point ? *derivedPointAPIObject : nullPoint, static_cast<Esri::GameEngine::Geometry::ArcGISLatitudeLongitudeFormat>(format), decimalPlaces);
    
    return localResult;
}

FString UArcGISCoordinateFormatter::ToMGRS(UArcGISPoint* point, EArcGISMGRSConversionMode::Type MGRSConversionMode, int32 precision, bool addSpaces)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISCoordinateFormatter::ToMGRS(point ? *derivedPointAPIObject : nullPoint, static_cast<Esri::GameEngine::Geometry::ArcGISMGRSConversionMode>(MGRSConversionMode), precision, addSpaces);
    
    return localResult;
}

FString UArcGISCoordinateFormatter::ToUSNG(UArcGISPoint* point, int32 precision, bool addSpaces)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISCoordinateFormatter::ToUSNG(point ? *derivedPointAPIObject : nullPoint, precision, addSpaces);
    
    return localResult;
}

FString UArcGISCoordinateFormatter::ToUTM(UArcGISPoint* point, EArcGISUTMConversionMode::Type UTMConversionMode, bool addSpaces)
{
    auto nullPoint = Esri::GameEngine::Geometry::ArcGISPoint{};
    auto derivedPointAPIObject = StaticCastSharedPtr<Esri::GameEngine::Geometry::ArcGISPoint>(point->APIObject);
    
    auto localResult = Esri::GameEngine::Geometry::ArcGISCoordinateFormatter::ToUTM(point ? *derivedPointAPIObject : nullPoint, static_cast<Esri::GameEngine::Geometry::ArcGISUTMConversionMode>(UTMConversionMode), addSpaces);
    
    return localResult;
}