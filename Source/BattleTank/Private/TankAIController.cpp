// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"




void ATankAIController::BeginPlay() {
	UE_LOG(LogTemp, Warning, TEXT("Begin play AI Controller"));
	
	ATank* ThisTank = GetControlledTankAI();
	
	if (!ThisTank)
	{
		UE_LOG(LogTemp, Error, TEXT("No AI Tank for you..."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI tank : %s"), *ThisTank->GetName());
	}

}

ATank* ATankAIController::GetControlledTankAI()
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerControlled()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	ATank* PlayerTank = nullptr;
	if (PlayerController) {
		PlayerTank = Cast<ATank>(PlayerController->GetPawn());
	}
	return PlayerTank;
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Tank AI Tick"));
	if (GetPlayerControlled()) {
		GetControlledTankAI()->AimAt(GetPlayerControlled()->GetActorLocation());
	}
	
}




