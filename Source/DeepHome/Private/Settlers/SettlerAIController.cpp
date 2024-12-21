// Fill out your copyright notice in the Description page of Project Settings.


#include "Settlers/SettlerAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Settlers/EnergyComponent.h"

void ASettlerAIController::BeginPlay()
{
	Super::BeginPlay();

	UBlackboardComponent* BlackboardComponent = GetBlackboardComponent();
	if (BehaviorTree && BlackboardData)
	{
		UseBlackboard(BlackboardData, BlackboardComponent);
		RunBehaviorTree(BehaviorTree);
	}
}

void ASettlerAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (UEnergyComponent* Energy = InPawn->FindComponentByClass<UEnergyComponent>())
	{
		Energy->OnEnergyExhaustedEvent.AddUObject(this, &ASettlerAIController::OnEnergyExhausted);
	}
}

void ASettlerAIController::OnEnergyExhausted()
{
	UE_LOG(LogTemp, Warning, TEXT("Energy exhausted"));
	if (UBlackboardComponent* BlackboardComponent = GetBlackboardComponent())
	{
		BlackboardComponent->SetValueAsBool("IsExhausted", true);
	}
}
