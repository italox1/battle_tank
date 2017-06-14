// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used to set maximum driving force, and yo apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()


public:
	// Sets a Throttle between -1 and +1 
	UFUNCTION(BlueprintCallable, Category= Input)
	void SetThrottle(float Throttle);

	// Max force per Track, in Newtons 
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000; // asume 40 tonne tank and 1g accelleration 
	
};
