// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TCAbilitySystemComponent.h"
#include "TCAttributeSet.h"
#include "GameFramework/Character.h"
#include "TCCharacterBase.generated.h"

UCLASS()
class SAMPLE_API ATCCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATCCharacterBase();
	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;

	void GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer, TArray<UTCGameplayAbility*>& ActiveAbilities) const;

protected:

	UPROPERTY()
	UTCAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UTCAttributeSet* AttributeSet;
};
