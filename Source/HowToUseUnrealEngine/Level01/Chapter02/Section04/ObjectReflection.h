#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectReflection.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API UObjectReflection : public USceneComponent
{
	GENERATED_BODY()

public:
	UObjectReflection();
	UFUNCTION(BlueprintCallable, Category = "Level01|Chapter02|Section04")
	void Print();

private:
	UPROPERTY(EditAnywhere)
	FString SchoolName;
};
