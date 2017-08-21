// Copyright ItaloD Ltd.
#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h" // So we can implement on death 



// Depends on movement component via pathfinding system


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!ensure(GetPawn())) { return; }
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	

	if (!ensure(PlayerTank) || !ensure(ControlledTank)) {	return;	}
	// Move Towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check if radius is in cm 

	// Aim at the player  
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>(); 
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// if aiming or lockd not fire 
	// Fire if ready
	if (AimingComponent->GetFiringState() == EFiringState::Locked) {
		AimingComponent->Fire(); //TODO limite fire rate XD
	}
	
		
}


void ATankAIController::OnPossessedTankDeath()
{
	if (!ensure(GetPawn())) { return; } // TODO Remoe if Okay
	GetPawn()->DetachFromControllerPendingDestroy();
	UE_LOG(LogTemp, Warning, TEXT("Received!"))
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn) {
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		// TODO Subscribe our local method to the tank's death event 
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}
