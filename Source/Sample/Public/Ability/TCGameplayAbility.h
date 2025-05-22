// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "TCGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLE_API UTCGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Ability)
	void ApplyEffectTest(TSubclassOf<UGameplayEffect> GameplayEffect);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GameplayEffect)
	TSubclassOf<UGameplayEffect> GameplayEffectClass;
};
