# include "Robot.h"

void URobot::Walk()
{
    UE_LOG(LogTemp, Log, TEXT("로봇이 걸었습니다."));
}

void URobot::Eat()
{
    UE_LOG(LogTemp, Log, TEXT("로봇이 전기를 충전합니다."));
}

void URobot::MakeSound()
{   
    UE_LOG(LogTemp, Log, TEXT("로봇이 삐삑! 하고 소리를 내었습니다."));
}