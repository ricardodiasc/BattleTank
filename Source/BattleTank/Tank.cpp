// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponnent"));

	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::AimAt(FVector HitLocation) {
	TankAimingComponent->AimAt(HitLocation, LauchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* Barrel) {
	TankAimingComponent->SetBarrel(Barrel);
	this->Barrel = Barrel;
}

void ATank::SetTurretReference(UTankTurret* Turret) {
	TankAimingComponent->SetTurret(Turret);
}

void ATank::Fire() {
	UE_LOG(LogTemp, Warning, TEXT("FIRE !!!"));

	if (!Barrel) {
		UE_LOG(LogTemp, Error, TEXT("No Barrel set on TANK"));
		return;
	}

	if (!ProjectileBlueprint) {
		UE_LOG(LogTemp, Error, TEXT("No ProjectileBlueprint for this TANK"));
		return;
	}

	FVector Location = Barrel->GetSocketLocation(FName("Projectile"));
	FRotator Rotation = Barrel->GetSocketRotation(FName("Projectile"));

	FActorSpawnParameters SpawnParameters; // To Discart....
	GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,Location,Rotation, SpawnParameters);

}