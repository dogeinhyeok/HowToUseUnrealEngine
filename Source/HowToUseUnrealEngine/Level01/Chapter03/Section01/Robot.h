#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Robot.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API URobot : public USceneComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="Level01|Chapter03|Section01")
    void Walk();
    
    UFUNCTION(BlueprintCallable, Category="Level01|Chapter03|Section01")
    void Eat();

    UFUNCTION(BlueprintCallable, Category="Level01|Chapter03|Section01")
    void MakeSound();
}; 