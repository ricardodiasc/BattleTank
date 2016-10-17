

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ATank* Tank = GetControlledTank();
	IsTickWorking = false;

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

	//TODO NExt
}
