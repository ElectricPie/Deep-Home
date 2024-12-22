// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Dwarf.generated.h"

class UHouseResidentComponent;
class UEnergyComponent;

UCLASS()
class DEEPHOME_API ADwarf : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADwarf();

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UEnergyComponent> EnergyComponent;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UHouseResidentComponent> HouseResidentComponent;
};
