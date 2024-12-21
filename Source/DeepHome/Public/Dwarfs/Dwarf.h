// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Dwarf.generated.h"

class UEnergyComponent;
class UHouse;

UCLASS()
class DEEPHOME_API ADwarf : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADwarf();
	virtual void Tick(float DeltaSeconds) override;
	void AssignHouse(UHouse* NewHouse);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UEnergyComponent> EnergyComponent;
	
	UPROPERTY(VisibleAnywhere)
	TWeakObjectPtr<UHouse> House;

};
