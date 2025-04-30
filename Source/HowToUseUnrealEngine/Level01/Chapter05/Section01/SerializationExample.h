#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SerializationExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API USerializationExample : public UGameInstance
{
	GENERATED_BODY()

public:	
	virtual void Init() override;
}; 
