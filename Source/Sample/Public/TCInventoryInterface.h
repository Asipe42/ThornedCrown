// Copyright (c) 2025 Modin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Item/TCItem.h"
#include "UObject/Interface.h"
#include "TCCommonTypes.h"
#include "TCInventoryInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTCInventoryInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SAMPLE_API ITCInventoryInterface
{
	GENERATED_BODY()

public:
	virtual UTCItem* GetSlottedItem(const FTCItemSlot& Slot) const = 0;
	virtual bool GetInventoryItemData(UTCItem* Item, FTCItemData& ItemData) const = 0;
};
