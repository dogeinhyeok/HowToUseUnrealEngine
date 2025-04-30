#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "StringExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UStringExample : public UGameInstance
{
	GENERATED_BODY()
	
public:	
	virtual void Init() override;
};
