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

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY TANK C++ construct  "), *TankName)

}

void ATank::BeginPlay() 
{
	Super::BeginPlay(); // Need to BP Begin Play to run!
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY TANK C++ BEGIN PLAY  "), *TankName)
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
	if ( !TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

}