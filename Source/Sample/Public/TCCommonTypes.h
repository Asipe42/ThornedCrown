#pragma once

#include "TCCommonTypes.generated.h"

USTRUCT(BlueprintType)
struct SAMPLE_API FTCItemSlot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	FPrimaryAssetType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	int32 SlotIndex;
};