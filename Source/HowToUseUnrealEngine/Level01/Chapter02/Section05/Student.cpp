#include "Student.h"

UStudent::UStudent()
{
    Name = TEXT("이인혁");
    Grade = 1;
    StudentNumber = 1;
}

void UStudent::DoLesson()
{
    Super::DoLesson();

    UE_LOG(LogTemp, Log, TEXT("%s 학생님이 %d학년 %d번 수업을 수강합니다."), *GetName(), Grade, StudentNumber);
}