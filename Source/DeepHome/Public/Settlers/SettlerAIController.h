// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SettlerAIController.generated.h"

/**
 * 
 */
UCLASS()
class DEEPHOME_API ASettlerAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UBlackboardData> BlackboardData;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UBehaviorTree> BehaviorTree;

private:
	void OnEnergyExhausted();
};
