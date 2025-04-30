#include "PrintExample.h"


void UPrintExample::Init()
{
	const FString MESSAGE_TEXT = TEXT("Hello Unreal");

	// 로그에 출력
	UE_LOG(LogTemp, Log, TEXT("%s"), *MESSAGE_TEXT);
	
	// 화면에 출력 (5초 동안, 빨간색으로)
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, *MESSAGE_TEXT);
	}
}
