// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/TCAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "TCCharacterBase.h"

void UTCAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetMaxHealthAttribute())
	{
		AdjustAttributeForMaxChange(Health, MaxHealth, NewValue, GetHealthAttribute());
	}
}

void UTCAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	ATCCharacterBase* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		AActor* TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetCharacter = Cast<ATCCharacterBase>(TargetActor);
	}
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		if (TargetCharacter)
		{
			TargetCharacter->HandleHealthChanged(Data.EvaluatedData.Magnitude);
		}
	}
}

void UTCAttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty) const
{
	UAbilitySystemComponent* AbilitySystem = GetOwningAbilitySystemComponent();
	const float CurrentMaxValue = MaxAttribute.GetCurrentValue();

	if (!AbilitySystem || FMath::IsNearlyEqual(CurrentMaxValue, NewMaxValue))
	{
		return;	
	}
	
	if (CurrentMaxValue == 0.f)
	{
		AbilitySystem->ApplyModToAttributeUnsafe(AffectedAttributeProperty, EGameplayModOp::Override, NewMaxValue);
		return;
	}

	const float CurrentValue = AffectedAttribute.GetCurrentValue();
	const float NewDelta = (CurrentValue * NewMaxValue / CurrentMaxValue) - CurrentValue;
	
	AbilitySystem->ApplyModToAttributeUnsafe(AffectedAttributeProperty, EGameplayModOp::Additive, NewDelta);
}
