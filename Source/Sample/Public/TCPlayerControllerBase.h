// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TCInventoryInterface.h"
#include "GameFramework/PlayerController.h"
#include "Item/TCItem.h"
#include "TCPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLE_API ATCPlayerControllerBase : public APlayerController, public ITCInventoryInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Inventory)
	void AddInventoryItem(UTCItem* NewItem, int32 ItemCount, int32 ItemLevel);

	UFUNCTION(BlueprintCallable, Category = Inventory)
	virtual void GetInventoryItemsWithType(TArray<UTCItem*>& OutItems, FPrimaryAssetType ItemType) override;

protected:
	TArray<UTCItem*> InventoryItems;
};
