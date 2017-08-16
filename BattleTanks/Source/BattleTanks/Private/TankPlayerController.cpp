// Copyright ItaloD Ltd.
#include "TankPlayerController.h"
#include "TankAimingComponent.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();	
	if (!ensure(AimingComponent)) { return; }

	FoundAimingComponent(AimingComponent);	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; } 

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {// Has "side-effect", is going to line trace		
		AimingComponent->AimAt(HitLocation);
	}	
}
//Get the world location if linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Fin the crosshair position in pixel coordinates
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);

	//"De-project" the screen position of the crosshair to a world direction		
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		//Line-trace along that direction, and see what we hit ( up to  max range)
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {	
	FVector CameraWroldLocation;//	To be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWroldLocation,
		LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)) {
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;//Line trace did't succeed;
}

