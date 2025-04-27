#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Person.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API UPerson : public USceneComponent
{
	GENERATED_BODY()

public:
	UPerson();

	UFUNCTION(BlueprintCallable, Category = "Level01|Chapter02|Section05")
	virtual void DoLesson();

	UFUNCTION(BlueprintCallable, Category = "Level01|Chapter02|Section05")
	const FString& GetName() const;

	UFUNCTION(BlueprintCallable, Category = "Level01|Chapter02|Section05")
	void SetName(const FString& InName);

protected:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 Grade;
};
