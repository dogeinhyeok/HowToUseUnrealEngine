# include "Farm.h"
# include "Cat.h"
# include "Dog.h"
# include "Robot.h"

void UFarm::Print()
{
    // 새로운 컴포넌트 인스턴스 생성
    UCat* Cat = NewObject<UCat>(this);
    UDog* Dog = NewObject<UDog>(this);
    URobot* Robot = NewObject<URobot>(this);

    // 컴포넌트 인스턴스를 Unreal Engine의 컴포넌트 시스템에 등록합니다
    Cat->RegisterComponent();
    Dog->RegisterComponent();
    Robot->RegisterComponent();

    // 컴포넌트 인스턴스를 배열에 추가
    TArray<USceneComponent*> Children = { Cat, Dog, Robot };

    // 배열에 있는 각 컴포넌트 인스턴스를 반복하여 처리
    for (const auto Child : Children)
    {
        IAnimalInterface* Animal = Cast<IAnimalInterface>(Child);
        if (Animal)
        {
            // 인터페이스 메서드를 직접 호출
            IAnimalInterface::Execute_Walk(Child);
            IAnimalInterface::Execute_Eat(Child);
            IAnimalInterface::Execute_MakeSound(Child);
        }
        else
        {
            // 로봇은 동물이 아니므로 로봇의 메서드를 직접 호출
            UE_LOG(LogTemp, Log, TEXT("로봇은 동물이 아닙니다."));
            Cast<URobot>(Child)->Walk();
            Cast<URobot>(Child)->Eat();
            Cast<URobot>(Child)->MakeSound();
        }
    }
}