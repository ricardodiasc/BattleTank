

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Custom Tank Barrel to make animations plausable

 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//Speed from 1 to -1
	void Elevation(float RelativeSpeed);

	UPROPERTY(Editanywhere, Category = Setup)
	float MaxDegreesPerSecond = 5.0f;

	UPROPERTY(Editanywhere, Category = Setup)
	float MaxElevationDegrees = 40.0;

	UPROPERTY(Editanywhere, Category = Setup)
	float MinElevationDegrees = 0.0f;
};
