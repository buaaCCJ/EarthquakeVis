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
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISDatumTransformation.h" // IWYU pragma: associated
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISGeographicTransformation.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISHorizontalVerticalTransformation.h"
#include "ArcGISMapsSDK/API/GameEngine/Geometry/ArcGISSpatialReference.h"
#include "ArcGISMapsSDK/API/Unreal/ArcGISErrorHandler.h"
#include "ArcGISMapsSDK/CAPI/GameEngine/Geometry/DatumTransformation.h"
#include "ArcGISMapsSDK/CAPI/Standard/String.h"

namespace Esri
{
namespace GameEngine
{
namespace Geometry
{
ArcGISSpatialReference ArcGISDatumTransformation::GetInputSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_DatumTransformation_getInputSpatialReference(reinterpret_cast<RT_DatumTransformationHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISDatumTransformation::GetIsMissingProjectionEngineFiles() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_DatumTransformation_getIsMissingProjectionEngineFiles(reinterpret_cast<RT_DatumTransformationHandle>(GetHandle()), &errorHandler);
    
    return localResult;
}

FString ArcGISDatumTransformation::GetName() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_DatumTransformation_getName(reinterpret_cast<RT_DatumTransformationHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = FString{};
    
    if (localResult != nullptr)
    {
        localLocalResult = FString{ RT_String_cStr(localResult, &errorHandler) };
        RT_String_destroy(localResult, &errorHandler);
    }
    
    return localLocalResult;
}

ArcGISSpatialReference ArcGISDatumTransformation::GetOutputSpatialReference() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_DatumTransformation_getOutputSpatialReference(reinterpret_cast<RT_DatumTransformationHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISSpatialReference{};
    
    if (localResult != nullptr)
    {
        localLocalResult = ArcGISSpatialReference{ localResult };
    }
    
    return localLocalResult;
}

bool ArcGISDatumTransformation::Equals(const ArcGISDatumTransformation& rightDatumTransformation) const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    const auto localRightDatumTransformation = static_cast<const RT_DatumTransformationHandle>(rightDatumTransformation.GetHandle());
    
    auto localResult = RT_DatumTransformation_equals(reinterpret_cast<RT_DatumTransformationHandle>(GetHandle()), localRightDatumTransformation, &errorHandler);
    
    return localResult;
}

ArcGISDatumTransformation ArcGISDatumTransformation::GetInverse() const
{
    auto errorHandler = Unreal::CreateErrorHandler();
    
    auto localResult = RT_DatumTransformation_getInverse(reinterpret_cast<RT_DatumTransformationHandle>(GetHandle()), &errorHandler);
    
    auto localLocalResult = ArcGISDatumTransformation{};
    
    if (localResult != nullptr)
    {
        auto objectTypeErrorHandler = Unreal::CreateErrorHandler();
        
        auto objectType = RT_DatumTransformation_getObjectType(localResult, &objectTypeErrorHandler);
        
        switch (objectType)
        {
            case RT_DatumTransformationType_geographicTransformation:
                localLocalResult = ArcGISGeographicTransformation{ localResult };
                break;
            case RT_DatumTransformationType_horizontalVerticalTransformation:
                localLocalResult = ArcGISHorizontalVerticalTransformation{ localResult };
                break;
            default:
                localLocalResult = ArcGISDatumTransformation{ localResult };
                break;
        }
    }
    
    return localLocalResult;
}

ArcGISDatumTransformation::ArcGISDatumTransformation(void* handle) :
    m_handle{ handle }
{
}

ArcGISDatumTransformation::ArcGISDatumTransformation(ArcGISDatumTransformation&& other) noexcept :
    m_handle{ other.m_handle }
{
    other.m_handle = nullptr;
}

ArcGISDatumTransformation::~ArcGISDatumTransformation()
{
    if (m_handle)
    {
        auto errorHandler = Unreal::CreateErrorHandler();
        
        RT_DatumTransformation_destroy(reinterpret_cast<RT_DatumTransformationHandle>(m_handle), &errorHandler);
    }
}

ArcGISDatumTransformation& ArcGISDatumTransformation::operator=(ArcGISDatumTransformation&& other) noexcept
{
    if (this != &other)
    {
        using std::swap;
        
        swap(m_handle, other.m_handle);
    }
    
    return *this;
}

ArcGISDatumTransformation::operator bool() const noexcept
{
    return m_handle != nullptr;
}

void* ArcGISDatumTransformation::GetHandle() const
{
    return m_handle;
}
void ArcGISDatumTransformation::SetHandle(void* handle)
{
    m_handle = handle;
}
} // namespace Geometry
} // namespace GameEngine
} // namespace Esri