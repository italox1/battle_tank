// Copyright ItaloD Ltd.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super we're replacing the functionality 
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto IAFowardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, IAFowardIntention);
	IntendMoveForwad(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, IAFowardIntention).Z;
	IntendTurnRight(RightThrow);
	UE_LOG(LogTemp, Warning, TEXT("Right : %f forward : %f "), RightThrow, ForwardThrow);

}


void UTankMovementComponent::IntendMoveForwad(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

}


