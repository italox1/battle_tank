// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank * GetControlledTank() const;

public: 
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//the crosshair intersects the world 
	void AimTowardsCrosshair();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
private:
	UPROPERTY(EditAnywhere)
	float  CrossHairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
	float  CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;
};
