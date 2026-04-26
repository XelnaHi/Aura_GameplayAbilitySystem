// Copyright Xelna

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"

#include "AuraAbilitySystemComponent.generated.h"


UCLASS()
class AURA_API UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	// Registering custom callbacks related to GE's after ASC AvatarActor has been confirmed to exist
	void AbilityActorInfoSet();
	
protected:
	// The custom callback to be registered
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
};
