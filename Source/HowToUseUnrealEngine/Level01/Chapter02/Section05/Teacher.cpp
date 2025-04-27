#include "Teacher.h"

UTeacher::UTeacher()
{
    Name = TEXT("이인혁");
    Grade = 1;
    TeacherNumber = 1;
}

void UTeacher::DoLesson()
{
    Super::DoLesson();

    UE_LOG(LogTemp, Log, TEXT("%s 강사님이 %d학년 %d번 수업을 진행합니다."), *GetName(), Grade, TeacherNumber);
}
