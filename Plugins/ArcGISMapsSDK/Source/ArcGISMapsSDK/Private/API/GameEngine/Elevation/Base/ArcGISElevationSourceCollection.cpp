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
#include "ArcGISMapsSDK/API/GameEngine/Elevation/ArcGISImageElevationSource.h"
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSource.h"
#include "ArcGISMapsSDK/API/GameEngine/Elevation/Base/ArcGISElevationSourceCollection.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/Unreal/ArcGISCollection.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/Base/GEElevationSource.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Elevation/Base/GEElevationSourceCollection.h"

namespace Esri
{
namespace GameEngine
{
namespace Elevation
{
namespace Base
{
ArcGISElevationSourceCollection::ArcGISElevationSourceCollection()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    SetHandle(RT_GEElevationSourceCollection_create(&errorHandler));
}

size_t ArcGISElevationSourceCollection::GetSize() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSourceCollection_getSize(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

size_t ArcGISElevationSourceCollection::Add(const ArcGISElevationSource& value)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_GEElevationSourceHandle>(value.GetHandle());
    
    auto localResult = RT_GEElevationSourceCollection_add(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

size_t ArcGISElevationSourceCollection::AddArray(const Unreal::ArcGISCollection<ArcGISElevationSource>& vector2)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localVector2 = static_cast<const RT_GEElevationSourceCollectionHandle>(vector2.GetHandle());
    
    auto localResult = RT_GEElevationSourceCollection_addArray(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), localVector2, &errorHandler);
    
    return localResult;
}

ArcGISElevationSource ArcGISElevationSourceCollection::At(size_t position) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSourceCollection_at(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), position, &errorHandler);
    
    auto localLocalResult = ArcGISElevationSource{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_GEElevationSource_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GEElevationSourceType_GEImageElevationSource:
                localLocalResult = ArcGISImageElevationSource{ localResult };
                break;
            default:
                localLocalResult = ArcGISElevationSource{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

bool ArcGISElevationSourceCollection::Contains(const ArcGISElevationSource& value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_GEElevationSourceHandle>(value.GetHandle());
    
    auto localResult = RT_GEElevationSourceCollection_contains(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

bool ArcGISElevationSourceCollection::Equals(const Unreal::ArcGISCollection<ArcGISElevationSource>& vector2) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localVector2 = static_cast<const RT_GEElevationSourceCollectionHandle>(vector2.GetHandle());
    
    auto localResult = RT_GEElevationSourceCollection_equals(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), localVector2, &errorHandler);
    
    return localResult;
}

ArcGISElevationSource ArcGISElevationSourceCollection::First() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSourceCollection_first(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISElevationSource{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_GEElevationSource_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GEElevationSourceType_GEImageElevationSource:
                localLocalResult = ArcGISImageElevationSource{ localResult };
                break;
            default:
                localLocalResult = ArcGISElevationSource{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

size_t ArcGISElevationSourceCollection::IndexOf(ArcGISElevationSource& value) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localValue = static_cast<RT_GEElevationSourceHandle>(value.GetHandle());
    
    auto localResult = RT_GEElevationSourceCollection_indexOf(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), localValue, &errorHandler);
    
    return localResult;
}

void ArcGISElevationSourceCollection::Insert(size_t position, const ArcGISElevationSource& value)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localValue = static_cast<const RT_GEElevationSourceHandle>(value.GetHandle());
    
    RT_GEElevationSourceCollection_insert(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), position, localValue, &errorHandler);
}

bool ArcGISElevationSourceCollection::IsEmpty() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSourceCollection_isEmpty(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

ArcGISElevationSource ArcGISElevationSourceCollection::Last() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSourceCollection_last(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISElevationSource{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_GEElevationSource_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_GEElevationSourceType_GEImageElevationSource:
                localLocalResult = ArcGISImageElevationSource{ localResult };
                break;
            default:
                localLocalResult = ArcGISElevationSource{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

void ArcGISElevationSourceCollection::Move(size_t oldPosition, size_t newPosition)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEElevationSourceCollection_move(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), oldPosition, newPosition, &errorHandler);
}

size_t ArcGISElevationSourceCollection::Npos()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_GEElevationSourceCollection_npos(&errorHandler);
    
    return localResult;
}

void ArcGISElevationSourceCollection::Remove(size_t position)
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEElevationSourceCollection_remove(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), position, &errorHandler);
}

void ArcGISElevationSourceCollection::RemoveAll()
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    RT_GEElevationSourceCollection_removeAll(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(GetHandle()), &errorHandler);
}

ArcGISElevationSourceCollection::ArcGISElevationSourceCollection(void* handle) :
    m_handle{ handle }
{
}

ArcGISElevationSourceCollection::ArcGISElevationSourceCollection(ArcGISElevationSourceCollection&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISElevationSourceCollection::~ArcGISElevationSourceCollection()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_GEElevationSourceCollection_destroy(reinterpret_cast<RT_GEElevationSourceCollectionHandle>(m_handle), &errorHandler);
    }
}

ArcGISElevationSourceCollection& ArcGISElevationSourceCollection::operator=(ArcGISElevationSourceCollection&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISElevationSourceCollection::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISElevationSourceCollection::GetHandle() const
{
    return m_handle;
}
void ArcGISElevationSourceCollection::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Base
} // namespace Elevation
} // namespace GameEngine
} // namespace Esri