#include "Person.h"

UPerson::UPerson()
{
    Name = TEXT("이인혁");
    Grade = 1;
}

void UPerson::DoLesson()
{
    UE_LOG(LogTemp, Log, TEXT("%s 님이 수업에 참여합니다."), *GetName());
}

const FString& UPerson::GetName() const
{
    return Name;
}

void UPerson::SetName(const FString& InName)
{
    Name = InName;
}