// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"




void ATankAIController::BeginPlay() {
	UE_LOG(LogTemp, Warning, TEXT("Begin play AI Controller"));
	
	ATank* ThisTank = GetControlledTankAI();
	ATank* PlayerTank = GetPlayerControlled();

	if (!ThisTank)
	{
		UE_LOG(LogTemp, Error, TEXT("No AI Tank for you..."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI tank : %s"), *ThisTank->GetName());
	}

	if (!PlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("AI not found player...."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Found player :%s"), *PlayerTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTankAI()
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerControlled()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	ATank* PlayerTank = nullptr;
	if (PlayerController) {
		PlayerTank = Cast<ATank>(PlayerController->GetPawn());
	}
	return PlayerTank;
}





