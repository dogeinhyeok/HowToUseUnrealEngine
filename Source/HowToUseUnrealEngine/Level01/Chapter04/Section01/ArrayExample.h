#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ArrayExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API UArrayExample : public USceneComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Level01|Chapter04|Section01")
	void Print();
}; 
