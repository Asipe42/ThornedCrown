// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TCCommonTypes.h"
#include "TCInventoryInterface.h"
#include "Ability/TCAbilitySystemComponent.h"
#include "Ability/TCAttributeSet.h"
#include "GameFramework/Character.h"
#include "Item/TCItem.h"
#include "TCCharacterBase.generated.h"

UCLASS()
class SAMPLE_API ATCCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ATCCharacterBase();
	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
	
	void InitializeAbilities();
	void InitializePassive();
	void InitializeDefaultAbilities();
	void InitializeSlottedAbilities();

	UFUNCTION(BlueprintCallable)
	float GetHealth() const;

	UFUNCTION(BlueprintCallable)
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void GetActiveAbilitiesWithTags(FGameplayTagContainer GameplayTagContainer, TArray<UTCGameplayAbility*>& ActiveAbilities) const;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool ActivateAbilityWithItemSlot(FTCItemSlot ItemSlot, bool bAllowRemoteActivation = true);

protected:
	TScriptInterface<ITCInventoryInterface> InventoryInterface;
	
	UPROPERTY()
	UTCAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UTCAttributeSet* AttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Abilities)
	TArray<TSubclassOf<UGameplayEffect>> Passive;

	virtual void HandleHealthChanged(float DeltaValue);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnChangedHealth(float DeltaValue);

	friend UTCAttributeSet; 
};
