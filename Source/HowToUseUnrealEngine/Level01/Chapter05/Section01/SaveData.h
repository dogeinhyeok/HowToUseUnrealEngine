#pragma once

#include "CoreMinimal.h"
#include "SaveData.generated.h"

USTRUCT()
struct HOWTOUSEUNREALENGINE_API FSaveData
{
	GENERATED_BODY()

	FSaveData() : Order(-1), Name(TEXT("이인혁")) {}
	FSaveData(int32 InOrder, const FString& InName) : Order(InOrder), Name(InName) {}

	// 파일 쓰기 연산자 오버로딩
	friend FArchive& operator<<(FArchive& Ar, FSaveData& Data)
	{
		Ar << Data.Order;
		Ar << Data.Name;
		return Ar;
	}

	UPROPERTY()
	int32 Order;

	UPROPERTY()
	FString Name;
};