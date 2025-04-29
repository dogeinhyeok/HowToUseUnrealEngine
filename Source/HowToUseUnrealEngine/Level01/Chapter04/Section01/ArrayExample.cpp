#include "ArrayExample.h"

static FString IntToString(const int32& Value)
{
	return FString::FromInt(Value);
}

void UArrayExample::Print()
{
	const int32 ArrayNum = 10;
	TArray<int32> Int32Array;

	// 1 2 3 4 5 6 7 8 9
	for (int32 i = 1; i <= ArrayNum; i++)
	{
		Int32Array.Add(i);
	}

	UE_LOG(LogTemp, Log, TEXT("Int32Array: %s"), *FString::JoinBy(Int32Array, TEXT(" "), &IntToString));

	// 1 3 5 7 9
	Int32Array.RemoveAll(
		[](int32 Value) 
		{
			return Value % 2 == 0;
		}
	);

	UE_LOG(LogTemp, Log, TEXT("Int32Array: %s"), *FString::JoinBy(Int32Array, TEXT(" "), &IntToString));

	// 1 3 5 7 9 2 4 6 8 10
	Int32Array += {2, 4, 6, 8, 10};

	UE_LOG(LogTemp, Log, TEXT("Int32Array: %s"), *FString::JoinBy(Int32Array, TEXT(" "), &IntToString));

	// C 스타일 배열과 TArray 간의 데이터 비교
	TArray<int32> Int32ArrayCompare;
	int32 CArray[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	Int32ArrayCompare.AddUninitialized(ArrayNum);

	// C 스타일 배열과 TArray 간의 데이터 복사
	FMemory::Memcpy(Int32ArrayCompare.GetData(), CArray, ArrayNum * sizeof(int32));
	check(Int32Array == Int32ArrayCompare);

	// 배열 요소의 합 구하기
	int32 Sum = 0;
	for (const int32& Int32Elem : Int32Array)
	{
		Sum += Int32Elem;
	}

	UE_LOG(LogTemp, Log, TEXT("Sum: %d"), Sum);
}