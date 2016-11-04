// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


ATankAIController::ATankAIController() {
	
}

void ATankAIController::BeginPlay() {

	Super::BeginPlay();
	//PrimaryActorTick.bCanEverTick = true;

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

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI found NO player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found player tank : %s"), *PlayerTank->GetName());
	}

}

ATank* ATankAIController::GetControlledTankAI()
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	ATank* PlayerTank = nullptr;
	if (PlayerController) {
		PlayerTank = Cast<ATank>(PlayerController->GetPawn());
	}
	if (!PlayerTank) {
		return nullptr;
	}
	else {
		return PlayerTank;
	}
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("AI is ticking..."));
	if (GetPlayerTank()) {

		GetControlledTankAI()->AimAt(GetPlayerTank()->GetActorLocation());
	}
	
}




