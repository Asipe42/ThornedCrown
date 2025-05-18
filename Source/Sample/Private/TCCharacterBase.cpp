// Fill out your copyright notice in the Description page of Project Settings.


#include "TCCharacterBase.h"

// Sets default values
ATCCharacterBase::ATCCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UTCAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	AttributeSet = CreateDefaultSubobject<UTCAttributeSet>(TEXT("AttributeSet"));
}

void ATCCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

void ATCCharacterBase::UnPossessed()
{
	Super::UnPossessed();
}

void ATCCharacterBase::GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer,TArray<UTCGameplayAbility*>& ActiveAbilities) const
{
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->GetActiveAbilitiesWithTags(GameplayTagContainer, ActiveAbilities);
	}
}
