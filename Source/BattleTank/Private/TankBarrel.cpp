

#include "BattleTank.h"
#include "TankBarrel.h"



void UTankBarrel::Elevation(float RelativeSpeed) {
	//UE_LOG(LogTemp, Warning, TEXT("Elevation in %f"), Degrees);
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, +1.0f);
	auto ElevationChange = MaxDegreesPerSecond * RelativeSpeed * GetWorld()->GetDeltaSeconds();
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	RawNewElevation = FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}
