// Fill out your copyright notice in the Description page of Project Settings.


#include "TCPlayerControllerBase.h"

#include "TCAssetManager.h"
#include "Item/TCWeaponItem.h"

void ATCPlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATCPlayerControllerBase::InitializeSlot(UTCItem* InitializeWeaponItem, UTCItem* InitializePotionItem)
{
	InventorySlots.Add(FTCItemSlot(UTCAssetManager::WeaponItemType, 0), InitializeWeaponItem);
	InventorySlots.Add(FTCItemSlot(UTCAssetManager::PotionItemType, 0), InitializePotionItem);
}

UTCItem* ATCPlayerControllerBase::GetInventorySlotItem(const FTCItemSlot& Slot) const
{
	return InventorySlots[Slot];
}

void ATCPlayerControllerBase::AddInventoryItem(UTCItem* NewItem, int32 ItemCount, int32 ItemLevel)
{
	for (int i = 0; i < ItemCount; i++)
	{
		InventoryItems.Add(NewItem);
	}
}

void ATCPlayerControllerBase::RemoveInventoryItem()
{
	if (InventoryItems.Num() > 0)
	{
		InventoryItems.RemoveAt(0);
	}
}

void ATCPlayerControllerBase::ClearInventory()
{
	
}

void ATCPlayerControllerBase::GetInventoryItem(UTCItem* OutItem)
{
	
}

void ATCPlayerControllerBase::GetInventoryItemsWithType(TArray<UTCItem*>& OutItems, FPrimaryAssetType ItemType)
{
	if (!ItemType.IsValid())
	{
		return;
	}

	for (auto Item : InventoryItems)
	{
		if (Item->ItemType == ItemType)
		{
			OutItems.Add(Item);
		}
	}
}
