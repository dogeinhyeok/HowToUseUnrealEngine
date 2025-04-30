# include "Cat.h"


void UCat::Walk_Implementation()
{
    UE_LOG(LogTemp, Log, TEXT("고양이가 걸었습니다."));
}

void UCat::Eat_Implementation()
{
    UE_LOG(LogTemp, Log, TEXT("고양이가 먹이를 먹었습니다."));
}

void UCat::MakeSound_Implementation()
{
    UE_LOG(LogTemp, Log, TEXT("고양이가 야옹! 하고 울었습니다."));
}