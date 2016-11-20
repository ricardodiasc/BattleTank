

#include "BattleTank.h"
#include "TankTrack.h"



void UTankTrack::SetThrottle(float Throttle) {
	//TODO Clamp Speed values.

	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s is at %f"), *Name, Throttle);
	
	FVector Force = GetForwardVector() * Throttle * TrackMaxDrivingForce;

	FVector Location = GetComponentLocation();

	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(Force, Location);
}
