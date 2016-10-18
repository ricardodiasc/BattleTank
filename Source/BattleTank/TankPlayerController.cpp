

#include "BattleTank.h"
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

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation)) {
		//TODO NExt
		UE_LOG(LogTemp, Warning, TEXT("HitLocation : %s"), *HitLocation.ToString());
	}

	
}


bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {
	int32 ViewportSizeX, ViewportSizeY;

	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	FVector LookDirection;

	if (GetLookDirection2D(ScreenLocation, LookDirection)) 
	{
		FVector Direction = LookDirection * 10000.0f;
		GetLookVectorHitLocation(LookDirection, Direction);
	}


	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& LookDirection, FVector& HitLocation) const {
	FHitResult ObjectHit;

	
	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start + (LineTraceDistance * LookDirection);

	bool result = GetWorld()->LineTraceSingleByChannel(ObjectHit, Start, End,ECC_Visibility);
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
	FVector WorldLocation;

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
	
}