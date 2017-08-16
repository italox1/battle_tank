// Copyright ItaloD Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"// Put new includes above ever


//Forward declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

public:	

	UFUNCTION(BlueprintCallable)
	void Fire();

	void AimAt(FVector HitLocation);

private:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 5000;
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBluePrint;

	// Local barrel referece for spawning projectile 
	UTankBarrel* Barrel = nullptr; // TODO remove this line 

	float ReloadTimeInSeconds = 3;
	double LastTimeFire=0;
};
