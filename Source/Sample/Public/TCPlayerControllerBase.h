// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TCCommonTypes.h"
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
	virtual void BeginPlay() override;

	void InitializeInventory();
	void InitializeSlot();
	
	UFUNCTION(BlueprintCallable, Category = Inventory)
	virtual void AddInventoryItem(UTCItem* NewItem, int32 ItemCount, int32 ItemLevel) override;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	virtual void RemoveInventoryItem() override;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	virtual void ClearInventory() override;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	virtual void GetInventoryItem(UTCItem* OutItem) override;
	
	UFUNCTION(BlueprintCallable, Category = Inventory)
	virtual void GetInventoryItemsWithType(TArray<UTCItem*>& OutItems, FPrimaryAssetType ItemType) override;

	
protected:
	UPROPERTY()
	TArray<UTCItem*> InventoryItems;
};
