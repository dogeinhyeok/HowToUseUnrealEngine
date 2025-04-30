#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BuildSystemExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UBuildSystemExample : public UGameInstance
{
	GENERATED_BODY()

public:	
	virtual void Init() override;
}; 
