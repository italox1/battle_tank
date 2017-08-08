// Copyright ItaloD Ltd.

#include "Tank.h"
#include "TankMovementComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"




// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastTimeFire) > ReloadTimeInSeconds;
	if (Barrel && isReloaded)
	{	
		// spawn a projectile at the socket location on the barrel 
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBluePrint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")));
	
		Projectile->LauncheProjectile(LaunchSpeed);
		LastTimeFire = FPlatformTime::Seconds();
	}

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

}