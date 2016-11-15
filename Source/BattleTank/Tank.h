// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()


protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
	

public:

	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LauchSpeed = 8000.0f; // TODO: Define ideal default 

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ATank::AimAt(FVector HitLocation);
	
	UFUNCTION(BlueprintCallable, Category="Setup")
	void SetBarrelReference(UTankBarrel* Barrel);

	UFUNCTION(BlueprintCallable, Category="Setup")
	void SetTurretReference(UTankTurret* Turrent);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void Fire();

private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	UTankBarrel* Barrel;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint = nullptr;
	

	float LastTimeFire = 0.0f;

	double ReloadTimeInSeconds = 3.0;


};
