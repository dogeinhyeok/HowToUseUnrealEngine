#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "InterfaceExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UInterfaceExample : public UGameInstance
{
    GENERATED_BODY()    

public:
    virtual void Init() override;
}; 