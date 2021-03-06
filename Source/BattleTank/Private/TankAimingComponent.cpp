

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LauchSpeed) {
	auto ThisTank = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at : %s from %s"), *ThisTank, *HitLocation.ToString(), *BarrelLocation.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("Lauch Speed = %f"), LauchSpeed);
	if (!Barrel) return;

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FVector EndLocation = HitLocation;
	FCollisionResponseParams ResponseParam;

	auto Time = GetWorld()->GetTimeSeconds();

	TArray <AActor*> ActorsToIgnore;
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, EndLocation, LauchSpeed, false, 0.0f, 0.0f, ESuggestProjVelocityTraceOption::DoNotTrace, ResponseParam, ActorsToIgnore, false)) {
		FVector Direction = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("%s Direction Velocity = %s"), *ThisTank, *Direction.ToString());
		MoveBarrel(Direction);
		//UE_LOG(LogTemp, Warning, TEXT("%f - aim found at %s"), Time, *Direction.ToString() )
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%f - NOT FOUND"), Time);
	}

}

void UTankAimingComponent::SetBarrel(UTankBarrel* Barrel) {
	this->Barrel = Barrel;
}


void UTankAimingComponent::MoveBarrel(FVector Direction) {
	if (!Barrel || !Turret) return;

	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = Direction.Rotation();
	FRotator DiferenceRotator = AimAsRotator - BarrelRotator;

	auto TurretRotator = Turret->GetForwardVector().Rotation();
	FRotator DiferenceTurretRotation = AimAsRotator - TurretRotator;

	Barrel->Elevation(DiferenceRotator.Pitch);
	Turret->Rotation(DiferenceTurretRotation.Yaw);

	
	//Move the right ammount in given time
	//given max elevation and frame time
	//TODO To finish latter....;
}

void UTankAimingComponent::SetTurret(UTankTurret* Turret) {
	this->Turret = Turret;
}