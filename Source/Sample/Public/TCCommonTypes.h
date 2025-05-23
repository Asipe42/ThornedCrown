#pragma once

#include "UObject/PrimaryAssetId.h"
#include "TCCommonTypes.generated.h"

USTRUCT(BlueprintType)
struct SAMPLE_API FTCItemSlot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FPrimaryAssetType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	int32 SlotIndex;
};