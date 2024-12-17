// Fill out your copyright notice in the Description page of Project Settings.


#include "Dwarfs/Dwarf.h"

// Sets default values
ADwarf::ADwarf()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADwarf::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADwarf::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADwarf::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

