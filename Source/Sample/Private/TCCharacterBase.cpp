// Fill out your copyright notice in the Description page of Project Settings.


#include "TCCharacterBase.h"

#include "TCAssetManager.h"
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

	InventoryInterface = NewController;
	
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

	InitializePassive();
	InitializeDefaultAbilities();	
	InitializeSlottedAbilities();
}

void ATCCharacterBase::InitializePassive()
{
	for (TSubclassOf<UGameplayEffect>& GameplayEffect : Passive)
	{
		FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
		EffectContext.AddSourceObject(this);

		FGameplayEffectSpecHandle NewHandle = AbilitySystemComponent->MakeOutgoingSpec(GameplayEffect, 1, EffectContext);
		if (NewHandle.IsValid())
		{
			FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(), AbilitySystemComponent);
		}
	}
}

void ATCCharacterBase::InitializeDefaultAbilities()
{
	if (GetLocalRole() != ROLE_Authority)
	{
		return;
	}
}

void ATCCharacterBase::InitializeSlottedAbilities()
{

}

float ATCCharacterBase::GetHealth() const
{
	return AttributeSet->GetHealth();
}

float ATCCharacterBase::GetMaxHealth() const
{
	return AttributeSet->GetMaxHealth();
}

void ATCCharacterBase::GetActiveAbilitiesWithTags(FGameplayTagContainer GameplayTagContainer,TArray<UTCGameplayAbility*>& ActiveAbilities) const
{
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->GetActiveAbilitiesWithTags(GameplayTagContainer, ActiveAbilities);
	}
}

bool ATCCharacterBase::ActivateAbilityWithItemSlot(const FTCItemSlot ItemSlot, const bool bAllowRemoteActivation)
{
	if (AbilitySystemComponent)
	{
		UTCItem* SlottedItem = InventoryInterface->GetSlottedItem(ItemSlot);
		if (!SlottedItem)
		{
			return false;
		}

		FTCItemData SlottedItemData;
		InventoryInterface->GetInventoryItemData(SlottedItem, SlottedItemData);
		if (SlottedItemData.ItemCount == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("SlottedItemData.ItemCount == 0"));
			return false;
		}
		
		const FGameplayAbilitySpecHandle Handle = AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(SlottedItem->GrantedAbility, SlottedItem->AbilityLevel, INDEX_NONE, this));
		AbilitySystemComponent->TryActivateAbility(Handle, bAllowRemoteActivation);

		return true;
	}
	
	return false;
}

void ATCCharacterBase::HandleHealthChanged(float DeltaValue)
{
	OnChangedHealth(DeltaValue);
}
