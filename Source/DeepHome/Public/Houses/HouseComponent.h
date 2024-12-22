// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HouseComponent.generated.h"

class UHouseResidentComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DEEPHOME_API UHouseComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHouseComponent();
	uint32 GetCurrentCapacity() const { return CurrentCapacity;}
	bool AddResident(UHouseResidentComponent* Resident);;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	uint32 MaxCapacity = 5;
	UPROPERTY(EditAnywhere)
	uint32 CurrentCapacity = 0;

private:
	UPROPERTY(VisibleAnywhere)
	TSet<TWeakObjectPtr<UHouseResidentComponent>> Residents;
};
