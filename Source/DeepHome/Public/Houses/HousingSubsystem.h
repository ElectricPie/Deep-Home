// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "HousingSubsystem.generated.h"

class UHouseComponent;
class UHouseResidentComponent;

/**
 * 
 */
UCLASS()
class DEEPHOME_API UHousingSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	void UpdateHouseCapacity(UHouseComponent* House, const uint32 AvailableCapacity);
	void RequestHouse(UHouseResidentComponent* Resident);

private:
	TSet<TWeakObjectPtr<UHouseComponent>> AvailableHouses;
	TSet<TWeakObjectPtr<UHouseComponent>> UnavailableHouses;

	TQueue<TWeakObjectPtr<UHouseResidentComponent>> ResidentsWaitingForHouse;
};
