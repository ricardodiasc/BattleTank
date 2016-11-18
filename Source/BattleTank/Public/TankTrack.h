

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	/* Set throttle force to Tank track. Speed changes from -1 to 1. */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Speed);
	
	
};
