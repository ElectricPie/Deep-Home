// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Dwarfs/Dwarf.h"
#include "Subsystems/WorldSubsystem.h"
#include "HousingSubsystem.generated.h"

class UHouse;

/**
 * 
 */
UCLASS()
class DEEPHOME_API UHousingSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	void UpdateHouseCapacity(UHouse* House, const uint32 AvailableCapacity);
	void RequestHouse(ADwarf* Dwarf);

private:
	TSet<TWeakObjectPtr<UHouse>> AvailableHouses;
	TSet<TWeakObjectPtr<UHouse>> UnavailableHouses;

	TQueue<TWeakObjectPtr<ADwarf>> DwarfsWaitingForHouse;
};
