#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SerializationJsonExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API USerializationJsonExample : public UGameInstance
{
	GENERATED_BODY()

public:	
	virtual void Init() override;

private:
	UPROPERTY()
	TObjectPtr<class USaveObject> SaveObject;
}; 
