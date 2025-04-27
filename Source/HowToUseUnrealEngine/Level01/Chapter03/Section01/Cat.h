#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimalInterface.h"
#include "Cat.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent) )
class HOWTOUSEUNREALENGINE_API UCat : public USceneComponent, public IAnimalInterface
{
    GENERATED_BODY()

public:
    // 인터페이스 메서드 구현
    void Walk_Implementation();
    
    void Eat_Implementation();
    
    void MakeSound_Implementation();
}; 