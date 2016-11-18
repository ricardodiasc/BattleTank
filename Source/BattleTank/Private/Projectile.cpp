

#include "BattleTank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovement->bAutoActivate = true;
	ProjectileMovement->Deactivate();
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AProjectile::LauchProjectile(float LaunchSpeed) {
	//UE_LOG(LogTemp, Warning, TEXT("Fire Projectile at speed %f"), LaunchSpeed);
	FVector Direction = FVector::ForwardVector * LaunchSpeed;
	ProjectileMovement->SetVelocityInLocalSpace(Direction);
}