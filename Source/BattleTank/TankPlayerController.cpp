

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay() {
	ATank* Tank = GetControlledTank();

	if (Tank)
	{
		UE_LOG(LogTemp, Error, TEXT("No tank for you..."));
	}

	UE_LOG(LogTemp, Warning, TEXT("Begin play called"));
}

ATank* ATankPlayerController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
}