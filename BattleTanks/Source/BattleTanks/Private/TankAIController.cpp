// Copyright ItaloD Ltd.
#include "TankAIController.h"
#include "Tank.h"

// Depends on movement component via pathfinding system


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank)) { 
		// Move Towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check if radius is in cm 

		// Aim at the player   
			ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
		ControlledTank->Fire(); //TODO limite fire rate XD
		}
}