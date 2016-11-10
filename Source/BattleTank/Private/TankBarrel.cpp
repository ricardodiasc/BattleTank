

#include "BattleTank.h"
#include "TankBarrel.h"



void UTankBarrel::Elevation(float RelativeSpeed) {
	//UE_LOG(LogTemp, Warning, TEXT("Elevation in %f"), Degrees);
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, +1.0f);
	auto ElevationChange =  RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	auto Elevation = FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
