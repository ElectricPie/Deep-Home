// Fill out your copyright notice in the Description page of Project Settings.


#include "Houses/House.h"

#include "Houses/HousingSubsystem.h"
#include "Dwarfs/Dwarf.h"

// Sets default values for this component's properties
UHouse::UHouse()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool UHouse::AddDwarf(ADwarf* Dwarf)
{
	if (Dwarf == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("UHouse::AddDwarf: Dwarf is null"));
		return false;
	}
	if (CurrentCapacity > 0)
	{
		return false;
	}

	UE_LOG(LogTemp, Warning, TEXT("Added %s to %s"), *Dwarf->GetName(), *GetName());
	Dwarfs.Add(Dwarf);
	Dwarf->AssignHouse(this);
	return true;
}

void UHouse::BeginPlay()
{
	Super::BeginPlay();

	if (UHousingSubsystem* HousingSubsystem = GetWorld()->GetSubsystem<UHousingSubsystem>())
	{
		HousingSubsystem->UpdateHouseCapacity(this, MaxCapacity - CurrentCapacity);
	}
}
