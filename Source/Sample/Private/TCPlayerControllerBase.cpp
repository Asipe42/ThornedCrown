// Fill out your copyright notice in the Description page of Project Settings.


#include "TCPlayerControllerBase.h"

void ATCPlayerControllerBase::GetInventoryItems(TArray<UTCItem*>& OutItems, FPrimaryAssetType ItemType)
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

void ATCPlayerControllerBase::AddInventoryItem(UTCItem* NewItem, int32 ItemCount, int32 ItemLevel)
{
	for (int i = 0; i < ItemCount; i++)
	{
		InventoryItems.Add(NewItem);
	}

	UE_LOG(LogTemp, Display, TEXT("Add Inventory Item"));
}
