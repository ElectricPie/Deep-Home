// Fill out your copyright notice in the Description page of Project Settings.


#include "Houses/HouseComponent.h"
#include "Houses/HouseResidentComponent.h"
#include "Houses/HousingSubsystem.h"

// Sets default values for this component's properties
UHouseComponent::UHouseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool UHouseComponent::AddResident(UHouseResidentComponent* Resident)
{
	if (Resident == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("UHouse::AddDwarf: Dwarf is null"));
		return false;
	}
	if (MaxCapacity - CurrentCapacity <= 0)
	{
		return false;
	}

	UE_LOG(LogTemp, Warning, TEXT("Added %s to %s"), *Resident->GetName(), *GetName());
	Residents.Add(Resident);
	Resident->AssignHouse(this);
	CurrentCapacity++;
	return true;
}

void UHouseComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UHousingSubsystem* HousingSubsystem = GetWorld()->GetSubsystem<UHousingSubsystem>())
	{
		HousingSubsystem->UpdateHouseCapacity(this, MaxCapacity - CurrentCapacity);
	}
}
