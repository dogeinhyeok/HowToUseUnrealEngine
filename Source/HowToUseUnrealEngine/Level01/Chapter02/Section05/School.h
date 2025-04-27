#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "School.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API USchool : public USceneComponent
{
	GENERATED_BODY()

public:
	USchool();
	
	UFUNCTION(BlueprintCallable, Category = "Level01|Chapter02|Section05")
	void Print();

private:
	UPROPERTY(EditAnywhere)
	FString SchoolName;
};
