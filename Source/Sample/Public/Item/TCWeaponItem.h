// Copyright (c) 2025 Modin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TCAssetManager.h"
#include "Item/TCItem.h"
#include "TCWeaponItem.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLE_API UTCWeaponItem : public UTCItem
{
	GENERATED_BODY()

public:
	
	UTCWeaponItem()
	{
		ItemType = UTCAssetManager::WeaponItemType;
	}
	
	UPROPERTY(EditAnywhere, BlueprintreadOnly, Category = Weapon)
	TSubclassOf<AActor> WeaponActor;
};
