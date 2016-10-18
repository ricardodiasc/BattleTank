

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
	}

	
}


bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {
	int32 ViewportSizeX, ViewportSizeY;

	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
//	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation : %s"), *ScreenLocation.ToString());

	FVector LookDirection;

	if (GetLookDirection2D(ScreenLocation, LookDirection)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("LookDirection: %s"), *LookDirection.ToString());
	}


	return true;
}


bool ATankPlayerController::GetLookDirection2D(FVector2D ScreenLocation, FVector& LookDirection) const{
	//To be discarted
	FVector WorldLocation;

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
	
}