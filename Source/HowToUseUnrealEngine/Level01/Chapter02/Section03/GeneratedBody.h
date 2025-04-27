#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GeneratedBody.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API UGeneratedBody : public USceneComponent
{
	GENERATED_BODY()

	// GENERATED_BODY() 매크로는 언리얼 헤더 툴(UHT)이 필수 코드를 자동으로 생성하게 합니다:
	// - 리플렉션 시스템에 필요한 정적 함수와 메타데이터 추가 (StaticClass() 등)
	// - 직렬화, 복제, 프로퍼티 접근 등의 기능 지원
	// - CDO(Class Default Object) 사용을 위한 코드 생성

	// 코드 자동 생성은 다음과 같은 과정을 거칩니다:
	// 1. UHT가 빌드 시 UnrealObject.generated.h 파일을 자동으로 생성합니다.
	// 2. 이 파일은 언리얼 엔진 기능을 사용하기 위한 코드로 Intermediate 폴더에 저장합니다.

public:	
	UFUNCTION(BlueprintCallable, Category = "Level01|Chapter02|Section03")
	void Print();
};
