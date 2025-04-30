#pragma once

#include "CoreMinimal.h"
#include "Animal.h"
#include "Dog.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UDog : public UObject, public IAnimal
{
    GENERATED_BODY()

public:
    // 인터페이스 메서드 구현
    void Walk_Implementation();
    
    void Eat_Implementation();

    void MakeSound_Implementation();
}; 