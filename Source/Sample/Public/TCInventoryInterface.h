// Copyright (c) 2025 Modin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Item/TCItem.h"
#include "UObject/Interface.h"
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

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void GetInventoryItemsWithType(TArray<UTCItem*>& OutItems, FPrimaryAssetType ItemType) = 0;
};
