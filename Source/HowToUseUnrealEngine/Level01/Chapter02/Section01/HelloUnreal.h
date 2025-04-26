#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HelloUnreal.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API UHelloUnreal : public USceneComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Level01|Chapter02|Section01")
	void Print();
}; 
