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

	UFUNCTION(BlueprintCallable)
	void InitializeSlot(UTCItem* InitializeWeaponItem, UTCItem* InitializePotionItem);

	UFUNCTION(BlueprintCallable, Category = Inventory)
	virtual UTCItem* GetSlottedItem(const FTCItemSlot& ItemSlot) const override;
	
	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool AddInventoryItem(UTCItem* NewItem, int32 ItemCount = 1, int32 ItemLevel = 1, bool bAutoSlot = true);
	
	UFUNCTION(BlueprintCallable, Category = Inventory)
	virtual bool RemoveInventoryItem(UTCItem* RemovedItem, int32 RemovedCount);

	virtual bool GetInventoryItemData(UTCItem* Item, FTCItemData& ItemData) const override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
	TMap<UTCItem*, FTCItemData> InventoryItem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
	TMap<FTCItemSlot, UTCItem*> SlottedItem;
};
