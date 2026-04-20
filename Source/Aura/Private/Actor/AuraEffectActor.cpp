// Copyright Xelna


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAttributeSet.h"


// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");

	SetRootComponent(Mesh);
	Sphere->SetupAttachment(GetRootComponent());
}

void AAuraEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                 UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
                                 const FHitResult& SweepResult)
{
	
	// TODO: Refactor to apply Gameplay Effect instead.
	if (IAbilitySystemInterface* IASC = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAuraAttributeSet* AuraAttributes = Cast<UAuraAttributeSet>(
			IASC->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));

		// Breaking consnt-ness. Big NO NO!
		UAuraAttributeSet* MutableAuraAttributes = const_cast<UAuraAttributeSet*>(AuraAttributes);
		MutableAuraAttributes->SetHealth(AuraAttributes->GetHealth() - 15.f);
		Destroy();
	}
}

void AAuraEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::EndOverlap);
}
