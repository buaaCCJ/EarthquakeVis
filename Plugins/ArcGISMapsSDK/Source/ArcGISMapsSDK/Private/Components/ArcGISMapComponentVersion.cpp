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
#include "ArcGISMapsSDK/Components/ArcGISMapComponentVersion.h"

#include "Serialization/CustomVersion.h"

const FGuid FArcGISMapComponentVersion::GUID(0x54df549d, 0xac6847f3, 0xb72f453f, 0xe1a55a47);

// Register the custom version with core
FCustomVersionRegistration GRegisterArcGISMapComponentVersion(FArcGISMapComponentVersion::GUID, FArcGISMapComponentVersion::LatestVersion, TEXT("ArcGISMapComponentVersion"));
