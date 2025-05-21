// Copyright (c) 2025 Modin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
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
};
