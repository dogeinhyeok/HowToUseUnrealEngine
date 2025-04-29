#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SetExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API USetExample : public USceneComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Level01|Chapter04|Section01")
	void Print();
}; 
