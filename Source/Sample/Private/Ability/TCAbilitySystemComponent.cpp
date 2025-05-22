// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/TCAbilitySystemComponent.h"

#include "Ability/TCGameplayAbility.h"

UTCAbilitySystemComponent::UTCAbilitySystemComponent()
{
}

void UTCAbilitySystemComponent::GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer, TArray<UTCGameplayAbility*>& ActiveAbilities) const
{
	TArray<FGameplayAbilitySpec*> ActivateSpecs;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(GameplayTagContainer, ActivateSpecs, false);

	for (const auto Spec : ActivateSpecs)
	{
		TArray<UGameplayAbility*> AbilityInstances = Spec->GetAbilityInstances();

		for (UGameplayAbility* ActiveAbility : AbilityInstances)
		{
			ActiveAbilities.Add(Cast<UTCGameplayAbility>(ActiveAbility));
		}
	}
}
