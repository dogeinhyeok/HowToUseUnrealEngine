#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PrintExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UPrintExample : public UGameInstance
{
	GENERATED_BODY()

public:	
	virtual void Init() override;
}; 
