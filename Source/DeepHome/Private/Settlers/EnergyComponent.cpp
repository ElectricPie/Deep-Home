// Fill out your copyright notice in the Description page of Project Settings.


#include "Settlers/EnergyComponent.h"

// Sets default values for this component's properties
UEnergyComponent::UEnergyComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called every frame
void UEnergyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	Energy -= PassiveEnergyDecay * DeltaTime;
	if (Energy <= 0)
	{
		Energy = 0;
		if (bIsExhaustedEventFired == false)
		{
			OnEnergyExhaustedEvent.Broadcast();
			bIsExhaustedEventFired = true;
		}
	}
}