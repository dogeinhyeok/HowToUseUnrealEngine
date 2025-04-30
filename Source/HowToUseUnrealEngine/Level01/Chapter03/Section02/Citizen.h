#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Citizen.generated.h"

UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UCitizen : public UObject
{
    GENERATED_BODY()

public:
    UCitizen();

    // 블루프린트에서 호출 가능한 getter/setter
    UFUNCTION(BlueprintPure, Category="Level01|Chapter03|Section02")
    FORCEINLINE class UCitizenCard* GetCitizenCard() const { return CitizenCard; }

    UFUNCTION(BlueprintCallable, Category="Level01|Chapter03|Section02")
    FORCEINLINE void SetCitizenCard(class UCitizenCard* InCitizenCard) { CitizenCard = InCitizenCard; }

protected:
    UPROPERTY()
    TObjectPtr<class UCitizenCard> CitizenCard;
};