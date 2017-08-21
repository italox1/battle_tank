// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()


protected:
	// How close can the AI tank get   
	UPROPERTY(EditDefaultsOnly, Category = "Setup")//Consider
	float AcceptanceRadius = 8000;
private:
	UFUNCTION()
	void OnPossessedTankDeath();
		
	//Called when start the game 
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;
	
};
