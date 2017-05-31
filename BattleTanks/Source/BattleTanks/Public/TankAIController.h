// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	
	//Called when start the game 
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Start the tank moving the barrel so what a shot would it where 
	//the crosshair intersects the world 
	void AimTowardsCrosshair();
private:
	ATank * GetControlledTank() const;
	ATank* GetPlayerTank() const;
	
};
