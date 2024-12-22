// Fill out your copyright notice in the Description page of Project Settings.


#include "Houses/HouseResidentComponent.h"
#include "Houses/HouseComponent.h"
#include "Houses/HousingSubsystem.h"

class UHousingSubsystem;
// Sets default values for this component's properties
UHouseResidentComponent::UHouseResidentComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UHouseResidentComponent::AssignHouse(UHouseComponent* NewHouse)
{
	House = NewHouse;
}

void UHouseResidentComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UHousingSubsystem* HousingSubsystem = GetWorld()->GetSubsystem<UHousingSubsystem>())
	{
		HousingSubsystem->RequestHouse(this);
	}
}

