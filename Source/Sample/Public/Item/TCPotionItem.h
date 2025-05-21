// Copyright (c) 2025 Modin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TCAssetManager.h"
#include "Item/TCItem.h"
#include "TCPotionItem.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLE_API UTCPotionItem : public UTCItem
{
	GENERATED_BODY()

public:
	UTCPotionItem()
	{
		ItemType = UTCAssetManager::PotionItemType;
	}
};
