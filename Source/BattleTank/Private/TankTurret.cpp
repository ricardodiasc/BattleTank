

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotation(float RelativeSpeed) {
	//UE_LOG(LogTemp, Warning, TEXT("Rotation at %f"), RelativeSpeed);
	
//	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
//	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	//auto RotationChange = RelativeSpeed * 100 * GetWorld()->DeltaTimeSeconds;

	auto NewRotation = RelativeRotation.Yaw + RelativeSpeed;

	//auto Rotation = FMath::Clamp<float>(NewRotation, -180, 180);

	
	SetRelativeRotation(FRotator(0.0f, NewRotation, 0.0f));

}

