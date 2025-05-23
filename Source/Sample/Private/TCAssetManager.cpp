// Copyright (c) 2025 Modin. All Rights Reserved.


#include "TCAssetManager.h"

const FPrimaryAssetType UTCAssetManager::PotionItemType = TEXT("Potion");
const FPrimaryAssetType UTCAssetManager::WeaponItemType = TEXT("Weapon");

UTCAssetManager& UTCAssetManager::Get()
{
	if (UTCAssetManager* This = Cast<UTCAssetManager> (GEngine->AssetManager))
	{
		return *This;
	}
	else
	{
		return *NewObject<UTCAssetManager>();
	}
}
