// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TopDownPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "Player/PlayerPawn.h"

void ATopDownPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		InputSubsystem->AddMappingContext(MappingContext, 0);
	}
}

void ATopDownPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATopDownPlayerController::Move);
	}
}

void ATopDownPlayerController::Move(const FInputActionValue& InputValue)
{
	const FVector2D MoveDirection = InputValue.Get<FVector2D>();
	if (APlayerPawn* PlayerPawn = Cast<APlayerPawn>(GetPawn()))
	{
		PlayerPawn->Move(MoveDirection);
	}
}
