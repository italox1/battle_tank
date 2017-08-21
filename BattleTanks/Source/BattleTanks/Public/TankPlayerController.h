// Copyright ItaloD Ltd.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

public: 
	virtual void SetPawn(APawn * InPawn) override;
	UFUNCTION()
	void OnPossessedTankDeath();
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
