// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/TCGameplayAbility.h"

#include "TCCharacterBase.h"

void UTCGameplayAbility::ApplyEffectTest(TSubclassOf<UGameplayEffect> GameplayEffect)
{
	FGameplayEffectSpecHandle SpecHandle = MakeOutgoingGameplayEffectSpec(GameplayEffect, 1);
	
	FGameplayAbilityTargetDataHandle TargetDataHandle;
	FGameplayAbilityTargetData_ActorArray* NewData = new FGameplayAbilityTargetData_ActorArray();

	AActor* OwningActor = GetOwningActorFromActorInfo();
	ATCCharacterBase* OwningCharacter = Cast<ATCCharacterBase>(OwningActor);
	TArray<AActor*> TargetActors;
	TargetActors.Add(OwningCharacter);
	NewData->TargetActorArray.Append(TargetActors);
	TargetDataHandle.Add(NewData);
	
	K2_ApplyGameplayEffectSpecToTarget(SpecHandle, TargetDataHandle);
}
