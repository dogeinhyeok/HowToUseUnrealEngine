#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Platform.generated.h"

UCLASS(ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent))
class HOWTOUSEUNREALENGINE_API UPlatform : public USceneComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Level01|Chapter03|Section03")
    void Print();
}; 