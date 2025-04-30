#include "ReflectionExample.h"


UReflectionExample::UReflectionExample()
{
    // 생성자에서 변수를 초기화하면 해당 값이 CDO(Class Default Object)에 저장됩니다.
    Value = TEXT("Default Value");
}

void UReflectionExample::Init()
{
    // 클래스 런타임 인스턴스와 컴파일 타임 인스턴스가 동일한지 확인합니다.
    UClass *ClassRuntime = GetClass();
    UClass *ClassCompileTime = UReflectionExample::StaticClass();

    check(ClassRuntime == ClassCompileTime);  // 거짓이면 프로그램을 중단
    ensure(ClassRuntime == ClassCompileTime);  // 거짓이면 에러 발생
    ensureMsgf(ClassRuntime != ClassCompileTime, TEXT("Fake Error"));  // 거짓이면 에러 메시지 출력

    UE_LOG(LogTemp, Log, TEXT("ClassRuntime: %s"), *ClassRuntime->GetName());
    UE_LOG(LogTemp, Log, TEXT("ClassCompileTime: %s"), *ClassCompileTime->GetName());

    // CDO(Class Default Object)는 여전히 생성자에서 설정한 "Default Value" 값을 유지합니다.
    UE_LOG(LogTemp, Log, TEXT("Value: %s"), *Value);
    Value = TEXT("Modified Value");
    UE_LOG(LogTemp, Log, TEXT("Value: %s"), *Value);
    UE_LOG(LogTemp, Log, TEXT("Value: %s"), *GetClass()->GetDefaultObject<UReflectionExample>()->Value);
}