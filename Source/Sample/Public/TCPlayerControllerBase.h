// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TCCommonTypes.h"
#include "TCInventoryInterface.h"
#include "GameFramework/PlayerController.h"
#include "Item/TCItem.h"
#include "Item/TCWeaponItem.h"
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

	UFUNCTION(BlueprintCallable)
	void InitializeSlot(UTCItem* InitializeWeaponItem, UTCItem* InitializePotionItem);

	virtual UTCItem* GetInventorySlotItem(const FTCItemSlot& Slot) const override;
	
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
	TArray<UTCItem*> InventoryItems;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
	TMap<FTCItemSlot, UTCItem*> InventorySlots;
};
