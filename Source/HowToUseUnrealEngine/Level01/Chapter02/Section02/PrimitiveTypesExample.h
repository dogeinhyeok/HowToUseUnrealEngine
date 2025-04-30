#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PrimitiveTypesExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UPrimitiveTypesExample : public UGameInstance
{
	GENERATED_BODY()

public:	
	virtual void Init() override;
}; 
