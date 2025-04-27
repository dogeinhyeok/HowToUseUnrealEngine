#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "City.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API UCity : public USceneComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="Level01|Chapter03|Section02")
    void Print();
}; 