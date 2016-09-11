

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay(){
    Super::BeginPlay();
    
    ATank* Tank = GetControlledTank();
    
    if(Tank){
        UE_LOG(LogTemp, Error, TEXT("ATank is missing!"));
        
    }else{
        UE_LOG(LogTemp, Warning, TEXT("Possessed player = %s"),Tank->GetFName());
    }
    
}

ATank* ATankPlayerController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
}