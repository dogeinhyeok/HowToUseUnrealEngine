#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "StructMapExample.generated.h"


USTRUCT()
struct FStudentData
{
	GENERATED_BODY()

	FStudentData()
	{
		Name = TEXT("None");
		Order = -1;
	}	

	FStudentData(FString InName, int32 InOrder)
	{
		Name = InName;
		Order = InOrder;
	}
	
	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 Order;
}; 

UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UStructMapExample : public UGameInstance
{
	GENERATED_BODY()

public:	
	virtual void Init() override;

private:
	TArray<FStudentData> StudentsData;
	TMap<int32, FString> StudentsMap;
}; 
