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
	UTCItem* const* FoundItem = SlottedItem.Find(ItemSlot);

	if (FoundItem)
	{
		return *FoundItem;
	}

	return nullptr;
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
		return true;
	}

	return false;
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

	return true;
}
