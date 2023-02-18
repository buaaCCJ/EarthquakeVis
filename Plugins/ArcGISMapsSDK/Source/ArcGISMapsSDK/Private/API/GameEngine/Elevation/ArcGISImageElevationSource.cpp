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
#include "ArcGISMapsSDK/API/GameEngine/Elevation/ArcGISImageElevationSource.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/GEImageElevationSource.h"

namespace Esri
{
namespace GameEngine
{
namespace Elevation
{
ArcGISImageElevationSource::ArcGISImageElevationSource(const FString& source, const FString& APIKey) :
    Base::ArcGISElevationSource{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEImageElevationSource_create(TCHAR_TO_ANSI(*source), TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

ArcGISImageElevationSource::ArcGISImageElevationSource(const FString& source, const FString& name, const FString& APIKey) :
    Base::ArcGISElevationSource{}
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEImageElevationSource_createWithName(TCHAR_TO_ANSI(*source), TCHAR_TO_ANSI(*name), TCHAR_TO_ANSI(*APIKey), &errorHandler));
}

ArcGISImageElevationSource::ArcGISImageElevationSource(void* handle) :
    Base::ArcGISElevationSource{ handle }
{
}

ArcGISImageElevationSource::ArcGISImageElevationSource(ArcGISImageElevationSource&& other) noexcept :
    Base::ArcGISElevationSource{ std::move(other) }
{
}

ArcGISImageElevationSource::ArcGISImageElevationSource() :
    Base::ArcGISElevationSource{}
{
}
} // namespace Elevation
} // namespace GameEngine
} // namespace Esri