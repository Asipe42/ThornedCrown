// Fill out your copyright notice in the Description page of Project Settings.


#include "TCPlayerControllerBase.h"

#include "TCAssetManager.h"

void ATCPlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATCPlayerControllerBase::InitializeSlot(TArray<UTCItem*> InitializeWeaponItem, UTCItem* InitializePotionItem)
{
	SlottedItem.Add(FTCItemSlot(UTCAssetManager::PotionItemType, 0), InitializePotionItem);

	for (int32 i = 0; i < InitializeWeaponItem.Num(); ++i)
	{
		SlottedItem.Add(FTCItemSlot(UTCAssetManager::WeaponItemType, i), InitializeWeaponItem[i]);
		InventoryItem.Add(InitializeWeaponItem[i], FTCItemData(1, 1));
	}
}

UTCItem* ATCPlayerControllerBase::GetSlottedItem(const FTCItemSlot& ItemSlot) const
{
	if (UTCItem* const* FoundItem = SlottedItem.Find(ItemSlot))
	{
		return *FoundItem;
	}

	return nullptr;
}

int32 ATCPlayerControllerBase::GetSlottedItemCount(const FTCItemSlot& Slot) const
{
	if (UTCItem* FoundSlottedItem = GetSlottedItem(Slot))
	{
		FTCItemData ItemData;
		GetInventoryItemData(FoundSlottedItem, ItemData);

		return ItemData.ItemCount;
	}

	return 0;
}

int32 ATCPlayerControllerBase::GetSlottedItemLevel(const FTCItemSlot& Slot) const
{
	if (UTCItem* FoundSlottedItem = GetSlottedItem(Slot))
	{
		FTCItemData ItemData;
		GetInventoryItemData(FoundSlottedItem, ItemData);

		return ItemData.ItemLevel;
	}

	return 0;
}

void ATCPlayerControllerBase::GetSlottedItemData(const FTCItemSlot& Slot, FTCItemData& OutData) const
{
	if (UTCItem* FoundSlottedItem = GetSlottedItem(Slot))
	{
		GetInventoryItemData(FoundSlottedItem, OutData);
		return;
	}

	OutData = FTCItemData();
}

bool ATCPlayerControllerBase::GetInventoryItemData(UTCItem* Item, FTCItemData& ItemData) const
{
	if (const FTCItemData* FoundData = InventoryItem.Find(Item))
	{
		ItemData = *FoundData;
		return true;
	}

	ItemData = FTCItemData();
	return false;
}

bool ATCPlayerControllerBase::AddInventoryItem(UTCItem* NewItem, int32 ItemCount, int32 ItemLevel, bool bAutoSlot)
{
	FTCItemData OldData;
	GetInventoryItemData(NewItem, OldData);
	
	FTCItemData NewData = OldData;
	NewData.UpdateItemData(FTCItemData(ItemCount, ItemLevel));

	if (OldData != NewData)
	{
		InventoryItem.Add(NewItem, NewData);
	}
	
	NotifyInventoryItemChanged();
	
	return true;
}

bool ATCPlayerControllerBase::RemoveInventoryItem(UTCItem* RemovedItem, int32 RemovedCount)
{
	if (!RemovedItem)
	{
		// TODO: Log Error
		return false;
	}

	FTCItemData NewData;
	GetInventoryItemData(RemovedItem, NewData);

	NewData.ItemCount -= RemovedCount;
	if (NewData.ItemCount > 0)
	{
		InventoryItem.Add(RemovedItem, NewData);
	}
	else
	{
		InventoryItem.Remove(RemovedItem);
	}

	NotifyInventoryItemChanged();

	return true;
}

int32 ATCPlayerControllerBase::GetInventoryItemCount(UTCItem* Item) const
{
	FTCItemData ItemData;
	GetInventoryItemData(Item, ItemData);

	return ItemData.ItemCount;
}

int32 ATCPlayerControllerBase::GetInventoryItemLevel(UTCItem* Item) const
{
	FTCItemData ItemData;
	GetInventoryItemData(Item, ItemData);

	return ItemData.ItemLevel;
}

void ATCPlayerControllerBase::NotifyInventoryItemChanged()
{
	InventoryItemChanged();
}
