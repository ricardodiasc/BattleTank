

#include "BattleTank.h"
#include "TankTrack.h"



void UTankTrack::SetThrottle(float Speed) {
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s is at %f"), *Name, Speed);

	//TODO Clamp Speed values.
}
