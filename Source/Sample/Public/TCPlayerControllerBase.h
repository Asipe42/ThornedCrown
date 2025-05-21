// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Item/TCItem.h"
#include "TCPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLE_API ATCPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Inventory)
	void GetInventoryItems(TArray<UTCItem*>& OutItems, FPrimaryAssetType ItemType);

	UFUNCTION(BlueprintCallable, Category = Inventory)
	void AddInventoryItem(UTCItem* NewItem, int32 ItemCount, int32 ItemLevel);

protected:
	TArray<UTCItem*> InventoryItems;
};
