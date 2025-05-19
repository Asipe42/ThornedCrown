// Fill out your copyright notice in the Description page of Project Settings.


#include "TCCharacterBase.h"

#include "Item/TCItem.h"

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
		InitializeAbilities();
	}
}

void ATCCharacterBase::UnPossessed()
{
	Super::UnPossessed();
}

void ATCCharacterBase::InitializeAbilities()
{
	check(AbilitySystemComponent);

	if (GetLocalRole() == ROLE_Authority)
	{
		InitializeDefaultAbilities();	
	}

	InitializeSlottedAbilities();
}

void ATCCharacterBase::InitializeDefaultAbilities()
{
}

void ATCCharacterBase::InitializeSlottedAbilities()
{
	FGameplayAbilitySpec SlottedAbilitySpec = FGameplayAbilitySpec(Item->GrantedAbility, Item->AbilityLevel);
	SlottedAbilities = AbilitySystemComponent->GiveAbility(SlottedAbilitySpec);
}

void ATCCharacterBase::GetActiveAbilitiesWithTags(FGameplayTagContainer GameplayTagContainer,TArray<UTCGameplayAbility*>& ActiveAbilities) const
{
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->GetActiveAbilitiesWithTags(GameplayTagContainer, ActiveAbilities);
	}
}

bool ATCCharacterBase::ActivateAbilities(bool bAllowRemoteActivation)
{
	if (AbilitySystemComponent)
	{
		return AbilitySystemComponent->TryActivateAbility(SlottedAbilities, bAllowRemoteActivation);
	}

	return false;
}