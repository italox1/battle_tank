// Copyright ItaloD Ltd.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"// Put new includes above ever

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	FTankDelegate OnDeath;

	// return between 0 and 1
	UFUNCTION(BlueprintPure,Category= "Health")
	float GetHealthPercent() const;

	//Call by the engine when actor damage is dealt
	virtual float TakeDamage(
		float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser) override;
	

private:
	virtual void BeginPlay() override;
	ATank();
	UPROPERTY(EditDefaultsOnly, Category= "Setup")
	int32 StartingHealth = 100;
	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth; // Initialise in Begin Play

};
