

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta =(BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 to +1
	void Rotation(float RelativeSpeed);
	
	UPROPERTY(Editanywhere, Category = Setup)
	float MaxDegreesPerSecond = 25.0f;
	
};
