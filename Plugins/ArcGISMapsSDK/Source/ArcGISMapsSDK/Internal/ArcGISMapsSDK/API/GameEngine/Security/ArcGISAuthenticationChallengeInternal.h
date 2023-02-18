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

namespace Esri
{
namespace GameEngine
{
namespace Security
{
enum class ArcGISAuthenticationChallengeType;

/// <summary>
/// Authentication challenge
/// </summary>
/// <since>1.0.0</since>
class ARCGISMAPSSDK_API ArcGISAuthenticationChallengeInternal
{
    friend class ArcGISAuthenticationChallengeInternal;

public:
    #pragma region Properties
    /// <summary>
    /// The current authentication challenge type
    /// </summary>
    /// <since>1.0.0</since>
    static ArcGISAuthenticationChallengeType GetObjectType(ArcGISAuthenticationChallenge* self);
    #pragma endregion Properties
};
} // namespace Security
} // namespace GameEngine
} // namespace Esri