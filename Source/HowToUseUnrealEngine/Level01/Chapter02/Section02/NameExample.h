#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NameExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UNameExample : public UGameInstance
{
	GENERATED_BODY()
	
public:	
	virtual void Init() override;
};