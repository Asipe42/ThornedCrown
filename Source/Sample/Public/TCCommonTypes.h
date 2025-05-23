#pragma once

#include "UObject/PrimaryAssetId.h"
#include "TCCommonTypes.generated.h"

USTRUCT(BlueprintType)
struct SAMPLE_API FTCItemSlot
{
	GENERATED_BODY()

	explicit FTCItemSlot(const FPrimaryAssetType ItemType = FPrimaryAssetType(), const int32 SlotIndex = 0)
		: ItemType(ItemType)
		, SlotIndex(SlotIndex)
	{
	}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FPrimaryAssetType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 SlotIndex;

	bool operator==(const FTCItemSlot& Other) const
	{
		return ItemType == Other.ItemType && SlotIndex == Other.SlotIndex;
	}

	bool operator!=(const FTCItemSlot& Other) const
	{
		return !(*this == Other);
	}
	
	friend inline uint32 GetTypeHash(const FTCItemSlot& Key)
	{
		/*
		 * Map, Set의 Key로 사용하기 위해서 Hash를 만들어야 한다.
		 */
		
		uint32 Hash = 0;

		Hash = HashCombine(Hash, GetTypeHash(Key.ItemType));
		Hash = HashCombine(Hash, (uint32)Key.SlotIndex);
		return Hash;
	}
};