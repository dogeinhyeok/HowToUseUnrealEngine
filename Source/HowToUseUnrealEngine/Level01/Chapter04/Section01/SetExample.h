#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SetExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API USetExample : public UGameInstance
{
	GENERATED_BODY()

public:	
	virtual void Init() override;
}; 
