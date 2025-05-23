// Copyright (c) 2025 Modin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "Item/TCItem.h"
#include "UObject/PrimaryAssetId.h"
#include "TCAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLE_API UTCAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static const FPrimaryAssetType PotionItemType;
	static const FPrimaryAssetType WeaponItemType;

	static UTCAssetManager& Get();
	UTCItem* ForceLoadInfo(const FPrimaryAssetId& PrimaryAssetId) const;
};
