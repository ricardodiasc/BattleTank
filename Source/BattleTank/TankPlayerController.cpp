

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ATank* Tank = GetControlledTank();

	if (Tank)
	{
		UE_LOG(LogTemp, Error, TEXT("No tank for you..."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Tank Posessed : %s"), *Tank->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("Begin play called"));
}

ATank* ATankPlayerController::GetControlledTank() const{
	APawn* TempPawn = GetControlledPawn();
	if (TempPawn) {
		UE_LOG(LogTemp, Error, TEXT("No Pawn for you..."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PAWN FOUND!!!"));
	}
	
	return Cast<ATank>(GetPawn());
}