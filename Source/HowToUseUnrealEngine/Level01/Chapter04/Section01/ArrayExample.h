#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ArrayExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UArrayExample : public UGameInstance
{
	GENERATED_BODY()

public:	
	virtual void Init() override;
}; 
