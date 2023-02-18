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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISEnvelope.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISPoint.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/VectorTile/ArcGISVectorTileSourceInfo.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/VectorTile/VectorTileSourceInfo.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace VectorTile
{
Geometry::ArcGISEnvelope ArcGISVectorTileSourceInfo::GetFullExtent() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfo_getFullExtent(reinterpret_cast<RT_VectorTileSourceInfoHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Geometry::ArcGISEnvelope{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Geometry::ArcGISEnvelope{ localResult };
    }
    
    return localLocalResult;
}

Geometry::ArcGISEnvelope ArcGISVectorTileSourceInfo::GetInitialExtent() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfo_getInitialExtent(reinterpret_cast<RT_VectorTileSourceInfoHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Geometry::ArcGISEnvelope{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Geometry::ArcGISEnvelope{ localResult };
    }
    
    return localLocalResult;
}

double ArcGISVectorTileSourceInfo::GetMaxScale() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfo_getMaxScale(reinterpret_cast<RT_VectorTileSourceInfoHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

double ArcGISVectorTileSourceInfo::GetMinScale() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfo_getMinScale(reinterpret_cast<RT_VectorTileSourceInfoHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

FString ArcGISVectorTileSourceInfo::GetName() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfo_getName(reinterpret_cast<RT_VectorTileSourceInfoHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

Geometry::ArcGISPoint ArcGISVectorTileSourceInfo::GetOrigin() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfo_getOrigin(reinterpret_cast<RT_VectorTileSourceInfoHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Geometry::ArcGISPoint{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Geometry::ArcGISPoint{ localResult };
    }
    
    return localLocalResult;
}

Geometry::ArcGISSpatialReference ArcGISVectorTileSourceInfo::GetSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfo_getSpatialReference(reinterpret_cast<RT_VectorTileSourceInfoHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = Geometry::ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = Geometry::ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

FString ArcGISVectorTileSourceInfo::GetURI() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfo_getURI(reinterpret_cast<RT_VectorTileSourceInfoHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISVectorTileSourceInfo::GetVersion() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileSourceInfo_getVersion(reinterpret_cast<RT_VectorTileSourceInfoHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

ArcGISVectorTileSourceInfo::ArcGISVectorTileSourceInfo(void* handle) :
    m_handle{ handle }
{
}

ArcGISVectorTileSourceInfo::ArcGISVectorTileSourceInfo(ArcGISVectorTileSourceInfo&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISVectorTileSourceInfo::~ArcGISVectorTileSourceInfo()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_VectorTileSourceInfo_destroy(reinterpret_cast<RT_VectorTileSourceInfoHandle>(m_handle), &errorHandler);
    }
}

ArcGISVectorTileSourceInfo& ArcGISVectorTileSourceInfo::operator=(ArcGISVectorTileSourceInfo&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISVectorTileSourceInfo::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISVectorTileSourceInfo::GetHandle() const
{
    return m_handle;
}
void ArcGISVectorTileSourceInfo::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace VectorTile
} // namespace Layers
} // namespace GameEngine
} // namespace Esri