// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability/TCAbilitySystemComponent.h"
#include "Ability/TCAttributeSet.h"
#include "GameFramework/Character.h"
#include "TCCharacterBase.generated.h"

UCLASS()
class SAMPLE_API ATCCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ATCCharacterBase();
	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void GetActiveAbilitiesWithTags(FGameplayTagContainer GameplayTagContainer, TArray<UTCGameplayAbility*>& ActiveAbilities) const;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool ActivateAbilities(bool bAllowRemoteActivation = true);

protected:

	UPROPERTY()
	UTCAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UTCAttributeSet* AttributeSet;
};
