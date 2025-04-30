#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CompositionExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UCompositionExample : public UGameInstance
{
    GENERATED_BODY()

public:
    virtual void Init() override;
}; 