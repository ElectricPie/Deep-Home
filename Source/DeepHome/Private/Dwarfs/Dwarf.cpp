// Fill out your copyright notice in the Description page of Project Settings.


#include "Dwarfs/Dwarf.h"
#include "Houses/HouseResidentComponent.h"
#include "Settlers/EnergyComponent.h"


// Sets default values
ADwarf::ADwarf()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnergyComponent = CreateDefaultSubobject<UEnergyComponent>(TEXT("Energy Component"));
	HouseResidentComponent = CreateDefaultSubobject<UHouseResidentComponent>(TEXT("House Resident Component"));
}