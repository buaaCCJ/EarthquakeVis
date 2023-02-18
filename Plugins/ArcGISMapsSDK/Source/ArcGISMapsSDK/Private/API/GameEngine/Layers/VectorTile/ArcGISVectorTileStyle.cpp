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
#include "ArcGISMapsSDK/API/GameEngine/Layers/VectorTile/ArcGISVectorTileStyle.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/VectorTile/VectorTileStyle.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace VectorTile
{
FString ArcGISVectorTileStyle::GetSourceURI() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileStyle_getSourceURI(reinterpret_cast<RT_VectorTileStyleHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

FString ArcGISVectorTileStyle::GetVersion() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_VectorTileStyle_getVersion(reinterpret_cast<RT_VectorTileStyleHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

ArcGISVectorTileStyle::ArcGISVectorTileStyle(void* handle) :
    m_handle{ handle }
{
}

ArcGISVectorTileStyle::ArcGISVectorTileStyle(ArcGISVectorTileStyle&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISVectorTileStyle::~ArcGISVectorTileStyle()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_VectorTileStyle_destroy(reinterpret_cast<RT_VectorTileStyleHandle>(m_handle), &errorHandler);
    }
}

ArcGISVectorTileStyle& ArcGISVectorTileStyle::operator=(ArcGISVectorTileStyle&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISVectorTileStyle::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISVectorTileStyle::GetHandle() const
{
    return m_handle;
}
void ArcGISVectorTileStyle::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace VectorTile
} // namespace Layers
} // namespace GameEngine
} // namespace Esri