#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
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

UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API UStructMapExample : public USceneComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Level01|Chapter04|Section02")
	void Print();

private:
	TArray<FStudentData> StudentsData;
	TMap<int32, FString> StudentsMap;
}; 
