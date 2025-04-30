#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DelegateExample.generated.h"


UCLASS(ClassGroup=(HowToUseUnrealEngine))
class HOWTOUSEUNREALENGINE_API UDelegateExample : public UGameInstance
{
    GENERATED_BODY()

public:
    virtual void Init() override;
}; 