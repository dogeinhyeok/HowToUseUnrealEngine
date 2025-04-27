# include "Dog.h"

void UDog::Walk_Implementation()
{
    UE_LOG(LogTemp, Log, TEXT("개가 걸었습니다."));
}

void UDog::Eat_Implementation()
{
    UE_LOG(LogTemp, Log, TEXT("개가 먹이를 먹었습니다."));
}

void UDog::MakeSound_Implementation()
{   
    UE_LOG(LogTemp, Log, TEXT("개가 멍멍! 하고 짖었습니다."));
}