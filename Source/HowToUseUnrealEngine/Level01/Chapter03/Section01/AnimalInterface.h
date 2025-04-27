# pragma once

# include "CoreMinimal.h"
# include "UObject/Interface.h"
# include "AnimalInterface.generated.h"

// 리플렉션 시스템에 등록되는 클래스
UINTERFACE(MinimalAPI, Blueprintable)
class UAnimalInterface : public UInterface
{
	GENERATED_BODY()
};

// 실제 인터페이스 기능을 정의하는 클래스
class IAnimalInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Level01|Chapter03|Section01")
    void Walk();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Level01|Chapter03|Section01")
    void Eat();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Level01|Chapter03|Section01")
    void MakeSound();
}; 