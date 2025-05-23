// Copyright (c) 2025 Modin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Ability/TCGameplayAbility.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "TCItem.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLE_API UTCItem : public UPrimaryDataAsset 
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
	FPrimaryAssetType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	FSlateBrush ItemIcon;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
	TSubclassOf<UTCGameplayAbility> GrantedAbility;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
	int32 AbilityLevel;
};
