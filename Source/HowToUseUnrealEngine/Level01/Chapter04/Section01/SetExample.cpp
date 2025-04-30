#include "SetExample.h"
#include "Common.h"


void USetExample::Init()
{
	TSet<int32> Int32Set;

	// 0 1 2 3 4 5 6 7 8 9
	for (int32 i = 0; i <= 10; i++)
	{
		Int32Set.Add(i);
	}

	UE_LOG(LogTemp, Log, TEXT("Int32Set: %s"), *FString::JoinBy(Int32Set, TEXT(" "), &IntToString));

	// 0 1 3 5 7 9
	Int32Set.Remove(2);
	Int32Set.Remove(4);
	Int32Set.Remove(6);
	Int32Set.Remove(8);
	Int32Set.Remove(10);

	UE_LOG(LogTemp, Log, TEXT("Int32Set: %s"), *FString::JoinBy(Int32Set, TEXT(" "), &IntToString));

	// 0 1 3 5 7 9 10
	Int32Set.Add(0); // 중복 추가
	Int32Set.Add(1); // 중복 추가
	Int32Set.Add(3); // 중복 추가
	Int32Set.Add(5); // 중복 추가
	Int32Set.Add(7); // 중복 추가
	Int32Set.Add(10);

	UE_LOG(LogTemp, Log, TEXT("Int32Set: %s"), *FString::JoinBy(Int32Set, TEXT(" "), &IntToString));
}