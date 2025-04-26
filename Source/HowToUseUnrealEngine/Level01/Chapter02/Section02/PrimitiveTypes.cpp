#include "PrimitiveTypes.h"

void UPrimitiveTypes::Print()
{
	// 기본 숫자 타입 선언
	int32 IntValue = 32;
    float FloatValue = 3.141592;
	UE_LOG(LogTemp, Log, TEXT("IntValue: %d, FloatValue: %f"), IntValue, FloatValue);

	// 숫자를 문자열(FString)로 변환
	FString IntString = FString::FromInt(IntValue);
	FString FloatString = FString::SanitizeFloat(FloatValue);
	UE_LOG(LogTemp, Log, TEXT("IntString: %s, FloatString: %s"), *IntString, *FloatString);

	// 문자열을 다시 숫자로 변환
	int32 IntValueFromString = FCString::Atoi(*IntString);
	float FloatValueFromString = FCString::Atof(*FloatString);
	UE_LOG(LogTemp, Log, TEXT("IntValueFromString: %d, FloatValueFromString: %f"), IntValueFromString, FloatValueFromString);
}
