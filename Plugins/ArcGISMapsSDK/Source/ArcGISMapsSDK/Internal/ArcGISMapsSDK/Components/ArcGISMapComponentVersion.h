// COPYRIGHT 1995-2021 ESRI
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

#include "CoreTypes.h"
#include "Misc/Guid.h"

// Custom serialization version for backwards compatibility during de-serialization
struct FArcGISMapComponentVersion
{
	FArcGISMapComponentVersion() = delete;

	enum Type
	{
		// Before any version changes were made
		BeforeCustomVersionWasAdded,

		// Rename properties for naming consistency
		PropertiesRename_1_1,

		// -----<new versions can be added above this line>-------------------------------------------------
		VersionPlusOne,
		LatestVersion = VersionPlusOne - 1
	};

	// The GUID for this custom version number
	const static FGuid GUID;
};
