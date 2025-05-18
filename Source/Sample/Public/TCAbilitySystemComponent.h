// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "TCGameplayAbility.h"
#include "TCAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLE_API UTCAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UTCAbilitySystemComponent();

	void GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer, TArray<UTCGameplayAbility*>& ActiveAbilities) const;
};
