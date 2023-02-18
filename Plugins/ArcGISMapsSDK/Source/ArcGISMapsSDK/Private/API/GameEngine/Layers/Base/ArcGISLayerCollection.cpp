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
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGIS3DObjectSceneLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISImageLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISIntegratedMeshLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISUnknownLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISUnsupportedLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/ArcGISVectorTileLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayer.h"
#include "ArcGISMapsSDK/API/GameEngine/Layers/Base/ArcGISLayerCollection.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISCollection.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayer.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Layers/Base/GELayerCollection.h"

namespace Esri
{
namespace GameEngine
{
namespace Layers
{
namespace Base
{
ArcGISLayerCollection::ArcGISLayerCollection()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GELayerCollection_create(&errorHandler));
}

size_t ArcGISLayerCollection::GetSize() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayerCollection_getSize(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISLayerCollection::Add(const ArcGISLayer& value)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_GELayerHandle>(value.GetHandle());
    
    auto localResult = RT_GELayerCollection_add(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

size_t ArcGISLayerCollection::AddArray(const Unreal::ArcGISCollection<ArcGISLayer>& vector2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localVector2 = static_cast<const RT_GELayerCollectionHandle>(vector2.GetHandle());
    
    auto localResult = RT_GELayerCollection_addArray(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), localVector2, &errorHandler);
    
    return localResult;
}

ArcGISLayer ArcGISLayerCollection::At(size_t position) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayerCollection_at(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), position, &errorHandler);
    
    auto localLocalResult = ArcGISLayer{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_GELayer_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GELayerType_GE3DObjectSceneLayer:
                localLocalResult = ArcGIS3DObjectSceneLayer{ localResult };
                break;
            case RT_GELayerType_GEImageLayer:
                localLocalResult = ArcGISImageLayer{ localResult };
                break;
            case RT_GELayerType_GEIntegratedMeshLayer:
                localLocalResult = ArcGISIntegratedMeshLayer{ localResult };
                break;
            case RT_GELayerType_GEUnknownLayer:
                localLocalResult = ArcGISUnknownLayer{ localResult };
                break;
            case RT_GELayerType_GEUnsupportedLayer:
                localLocalResult = ArcGISUnsupportedLayer{ localResult };
                break;
            case RT_GELayerType_GEVectorTileLayer:
                localLocalResult = ArcGISVectorTileLayer{ localResult };
                break;
            default:
                localLocalResult = ArcGISLayer{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

bool ArcGISLayerCollection::Contains(const ArcGISLayer& value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_GELayerHandle>(value.GetHandle());
    
    auto localResult = RT_GELayerCollection_contains(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

bool ArcGISLayerCollection::Equals(const Unreal::ArcGISCollection<ArcGISLayer>& vector2) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localVector2 = static_cast<const RT_GELayerCollectionHandle>(vector2.GetHandle());
    
    auto localResult = RT_GELayerCollection_equals(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), localVector2, &errorHandler);
    
    return localResult;
}

ArcGISLayer ArcGISLayerCollection::First() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayerCollection_first(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISLayer{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_GELayer_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GELayerType_GE3DObjectSceneLayer:
                localLocalResult = ArcGIS3DObjectSceneLayer{ localResult };
                break;
            case RT_GELayerType_GEImageLayer:
                localLocalResult = ArcGISImageLayer{ localResult };
                break;
            case RT_GELayerType_GEIntegratedMeshLayer:
                localLocalResult = ArcGISIntegratedMeshLayer{ localResult };
                break;
            case RT_GELayerType_GEUnknownLayer:
                localLocalResult = ArcGISUnknownLayer{ localResult };
                break;
            case RT_GELayerType_GEUnsupportedLayer:
                localLocalResult = ArcGISUnsupportedLayer{ localResult };
                break;
            case RT_GELayerType_GEVectorTileLayer:
                localLocalResult = ArcGISVectorTileLayer{ localResult };
                break;
            default:
                localLocalResult = ArcGISLayer{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

size_t ArcGISLayerCollection::IndexOf(ArcGISLayer& value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localValue = static_cast<RT_GELayerHandle>(value.GetHandle());
    
    auto localResult = RT_GELayerCollection_indexOf(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

void ArcGISLayerCollection::Insert(size_t position, const ArcGISLayer& value)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_GELayerHandle>(value.GetHandle());
    
    RT_GELayerCollection_insert(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), position, localValue, &errorHandler);
}

bool ArcGISLayerCollection::IsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayerCollection_isEmpty(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISLayer ArcGISLayerCollection::Last() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayerCollection_last(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISLayer{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_GELayer_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GELayerType_GE3DObjectSceneLayer:
                localLocalResult = ArcGIS3DObjectSceneLayer{ localResult };
                break;
            case RT_GELayerType_GEImageLayer:
                localLocalResult = ArcGISImageLayer{ localResult };
                break;
            case RT_GELayerType_GEIntegratedMeshLayer:
                localLocalResult = ArcGISIntegratedMeshLayer{ localResult };
                break;
            case RT_GELayerType_GEUnknownLayer:
                localLocalResult = ArcGISUnknownLayer{ localResult };
                break;
            case RT_GELayerType_GEUnsupportedLayer:
                localLocalResult = ArcGISUnsupportedLayer{ localResult };
                break;
            case RT_GELayerType_GEVectorTileLayer:
                localLocalResult = ArcGISVectorTileLayer{ localResult };
                break;
            default:
                localLocalResult = ArcGISLayer{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

void ArcGISLayerCollection::Move(size_t oldPosition, size_t newPosition)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GELayerCollection_move(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), oldPosition, newPosition, &errorHandler);
}

size_t ArcGISLayerCollection::Npos()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GELayerCollection_npos(&errorHandler);
    
    return localResult;
}

void ArcGISLayerCollection::Remove(size_t position)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GELayerCollection_remove(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), position, &errorHandler);
}

void ArcGISLayerCollection::RemoveAll()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GELayerCollection_removeAll(reinterpret_cast<RT_GELayerCollectionHandle>(GetHandle()), &errorHandler);
}

ArcGISLayerCollection::ArcGISLayerCollection(void* handle) :
    m_handle{ handle }
{
}

ArcGISLayerCollection::ArcGISLayerCollection(ArcGISLayerCollection&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISLayerCollection::~ArcGISLayerCollection()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GELayerCollection_destroy(reinterpret_cast<RT_GELayerCollectionHandle>(m_handle), &errorHandler);
    }
}

ArcGISLayerCollection& ArcGISLayerCollection::operator=(ArcGISLayerCollection&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISLayerCollection::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISLayerCollection::GetHandle() const
{
    return m_handle;
}
void ArcGISLayerCollection::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Base
} // namespace Layers
} // namespace GameEngine
} // namespace Esri