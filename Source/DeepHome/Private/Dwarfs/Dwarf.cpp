// Fill out your copyright notice in the Description page of Project Settings.


#include "Dwarfs/Dwarf.h"
#include "Houses/HousingSubsystem.h"
#include "Houses/House.h"

// Sets default values
ADwarf::ADwarf()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADwarf::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Energy Decay
	const float DeltaEnergyLost = PassiveEnergyDecay * DeltaSeconds;
	Energy -= DeltaEnergyLost;
	if (Energy <= 0)
	{
		Energy = 0;
		// TODO: Implement exhaustion
	}
}

void ADwarf::AssignHouse(UHouse* NewHouse)
{
	House = NewHouse;
}

void ADwarf::BeginPlay()
{
	Super::BeginPlay();

	if (UHousingSubsystem* HousingSubsystem = GetWorld()->GetSubsystem<UHousingSubsystem>())
	{
		HousingSubsystem->RequestHouse(this);
	}
}
