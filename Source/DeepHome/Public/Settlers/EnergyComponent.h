// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnergyComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnEnergyExhaustedSignature);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEEPHOME_API UEnergyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	FOnEnergyExhaustedSignature OnEnergyExhaustedEvent;
	
public:	
	// Sets default values for this component's properties
	UEnergyComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	bool IsExhausted() const { return Energy <= 0; }

private:
	UPROPERTY(EditAnywhere)
	float Energy = 100.f;
	UPROPERTY(EditAnywhere, meta=(ToolTip="The amount of energy lost per decay time"))
	float PassiveEnergyDecay = 1.f;

	bool bIsExhaustedEventFired = false;
};
