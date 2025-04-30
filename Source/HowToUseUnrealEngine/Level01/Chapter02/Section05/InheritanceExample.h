#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "InheritanceExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UInheritanceExample : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
};
