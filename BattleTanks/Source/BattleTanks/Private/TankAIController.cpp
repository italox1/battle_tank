// Copyright ItaloD Ltd.
#include "TankAIController.h"
#include "TankAimingComponent.h"


// Depends on movement component via pathfinding system


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank) && !ensure(ControlledTank)) {	return;	}
	// Move Towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check if radius is in cm 

	// Aim at the player  
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>(); 
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// Fire if ready
	AimingComponent->Fire(); //TODO limite fire rate XD
		
}