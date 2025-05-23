// Fill out your copyright notice in the Description page of Project Settings.


#include "TCPlayerControllerBase.h"

void ATCPlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	InitializeInventory();
	InitializeSlot();
}

void ATCPlayerControllerBase::InitializeInventory()
{
}

void ATCPlayerControllerBase::InitializeSlot()
{
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
