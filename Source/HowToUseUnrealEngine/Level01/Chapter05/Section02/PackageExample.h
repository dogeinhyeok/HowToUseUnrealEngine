#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PackageExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UPackageExample : public UGameInstance
{
	GENERATED_BODY()

public:	
	virtual void Init() override;
}; 
