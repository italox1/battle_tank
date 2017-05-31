// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"




ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find a player tank "));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIController found: %s"), *(PlayerTank->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("LLamadas al tick frame "));

}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr;}
	return Cast<ATank>(PlayerTank);
}

void ATankAIController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	//Get the world location if linetrace through crosshair 
	//if it hits the landScape 
		//Tell controlled tank to aim this point 

}


