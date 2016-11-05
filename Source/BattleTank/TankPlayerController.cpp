

#include "BattleTank.h"
#include "Tank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ATank* Tank = GetControlledTank();

	//If you came because of the post. this was the error
	if (!Tank)
	{
		UE_LOG(LogTemp, Error, TEXT("No tank for you..."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Tank POSSUIDO!!! : %s"), *Tank->GetName());
	}

}

ATank* ATankPlayerController::GetControlledTank() const{
	
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

//Tick
void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) return;

	FVector HitLocation = FVector(0);

	if (GetSightRayHitLocation(HitLocation)) {
		GetControlledTank()->AimAt(HitLocation);
	}

	
}

//Tick
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {
	int32 ViewportSizeX, ViewportSizeY;

	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	FVector LookDirection;
	if (GetLookDirection2D(ScreenLocation, LookDirection)) 
	{
		return GetLookVectorHitLocation(LookDirection, HitLocation);
	}


	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& LookDirection, FVector& HitLocation) const {
	FHitResult ObjectHit;

	
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LineTraceDistance * LookDirection);

	bool result = GetWorld()->LineTraceSingleByChannel(ObjectHit, StartLocation, EndLocation,ECC_Visibility);
	if (result) {
		HitLocation = ObjectHit.Location;
	}
	else {
		HitLocation = FVector(0);
	}
	return result;
}

bool ATankPlayerController::GetLookDirection2D(FVector2D ScreenLocation, FVector& LookDirection) const{
	//To be discarted
	FVector CameraWorldLocation;

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	
}