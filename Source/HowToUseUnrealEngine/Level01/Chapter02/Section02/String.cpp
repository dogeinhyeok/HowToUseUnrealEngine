#include "String.h"


void UString::Print()
{
	// 언리얼 문자열 기본 사용법
	TCHAR LogCharArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, TEXT("%s"), LogCharArray);

	// TCHAR 배열에서 FString으로 변환
	FString LogCharString = LogCharArray;
	UE_LOG(LogTemp, Log, TEXT("%s"), *LogCharString);

	// FString과 TCHAR 포인터 간 변환 및 데이터 접근
	const TCHAR *LongCharPtr = *LogCharString;
	TCHAR* LogCharDataPtr = LogCharString.GetCharArray().GetData();

	// 문자열 복사
	TCHAR LogCharArrayWithSize[100];
	FCString::Strcpy(LogCharArrayWithSize, LogCharString.Len(), *LogCharString);

	// 문자열 검색 및 부분 문자열 추출
	if (LogCharString.Contains(TEXT("unreal"), ESearchCase::IgnoreCase))
	{
		int32 Index = LogCharString.Find(TEXT("unreal"), ESearchCase::IgnoreCase);
		FString FoundString = LogCharString.Mid(Index);
		UE_LOG(LogTemp, Log, TEXT("%s"), *FoundString);
	}

	// 문자열 분할
	FString Left, Right;
	if (LogCharString.Split(TEXT(" "), &Left, &Right))
	{
		UE_LOG(LogTemp, Log, TEXT("Left: %s, Right: %s"), *Left, *Right);
	}	
}
