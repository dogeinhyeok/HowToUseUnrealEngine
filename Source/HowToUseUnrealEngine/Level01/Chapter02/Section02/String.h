#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "String.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API UString : public USceneComponent
{
	GENERATED_BODY()
	
public:	
	UFUNCTION(BlueprintCallable, Category = "Level01|Chapter02|Section02")
	void Print();
};
