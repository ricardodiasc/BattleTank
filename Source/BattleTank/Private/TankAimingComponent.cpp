

#include "BattleTank.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

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
	TArray <AActor*> ActorsToIgnore;
	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, EndLocation, LauchSpeed, false, 0.0f, false, ESuggestProjVelocityTraceOption::TraceFullPath, ResponseParam, ActorsToIgnore, true)) {
		FVector Direction = OutLaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("%s Direction Velocity = %s"), *ThisTank, *Direction.ToString());

		MoveBarrel(Direction);
	}

}

void UTankAimingComponent::SetBarrel(UStaticMeshComponent* Barrel) {
	this->Barrel = Barrel;
}


void UTankAimingComponent::MoveBarrel(FVector Direction) {
	if (!Barrel) return;
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimToRotator = Direction.Rotation();
	FRotator DiferenceRotator = BarrelRotator - AimToRotator;

	//Move the right ammount in given time
	//given max elevation and frame time
	//TODO To finish latter....;
}