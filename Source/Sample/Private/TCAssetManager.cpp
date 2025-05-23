// Copyright (c) 2025 Modin. All Rights Reserved.


#include "TCAssetManager.h"

#include "Item/TCItem.h"

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

UTCItem* UTCAssetManager::ForceLoadInfo(const FPrimaryAssetId& PrimaryAssetId) const
{
	FSoftObjectPath ItemPath = GetPrimaryAssetPath(PrimaryAssetId);
	UTCItem* LoadedItem = Cast<UTCItem>(ItemPath.TryLoad());

	return LoadedItem;
}
