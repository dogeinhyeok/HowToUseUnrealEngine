#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CitizenCard.generated.h"

UENUM(BlueprintType)
enum class EJob : uint8
{
    Unemployed UMETA(DisplayName = "Unemployed"),
    Farmer UMETA(DisplayName = "Farmer"),
    Builder UMETA(DisplayName = "Builder"),
    Doctor UMETA(DisplayName = "Doctor")
};

UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UCitizenCard : public UObject
{
    GENERATED_BODY()

public:
    UCitizenCard();

    EJob GetJob() const { return Job; }
    void SetJob(EJob InJob) { Job = InJob; }

private:
    UPROPERTY() 
    EJob Job;  
};