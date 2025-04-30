#pragma once

#include "CoreMinimal.h"
#include "SaveObject.generated.h"


UCLASS()
class HOWTOUSEUNREALENGINE_API USaveObject : public UObject
{
	GENERATED_BODY()
	
public:
    USaveObject();

    int32 GetOrder() const { return Order; }
    const FString& GetName() const { return Name; }

    void SetOrder(int32 InOrder) { Order = InOrder; }
    void SetName(const FString& InName) { Name = InName; }

    virtual void Serialize(FArchive& Ar) override;

private:
	UPROPERTY()
	int32 Order;

	UPROPERTY()
	FString Name;
};