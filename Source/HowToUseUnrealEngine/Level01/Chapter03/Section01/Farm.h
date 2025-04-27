#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Farm.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API UFarm : public USceneComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="Level01|Chapter03|Section01")
    void Print();
}; 