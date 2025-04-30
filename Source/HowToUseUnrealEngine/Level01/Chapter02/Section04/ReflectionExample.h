#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ReflectionExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UReflectionExample : public UGameInstance
{
	GENERATED_BODY()

public:
	UReflectionExample();
	
	virtual void Init() override;

private:
	UPROPERTY(EditAnywhere)
	FString Value;
}; 