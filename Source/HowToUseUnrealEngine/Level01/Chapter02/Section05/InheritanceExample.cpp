#include "InheritanceExample.h"
#include "Student.h"
#include "Teacher.h"


void UInheritanceExample::Init()
{
    UStudent *Student = NewObject<UStudent>(this);
    UTeacher *Teacher = NewObject<UTeacher>(this);

    Teacher->DoLesson();
    Student->DoLesson();

    UE_LOG(LogTemp, Log, TEXT("---"));

    // SetName 함수로 변수 수정
    Student->SetName(TEXT("홍길동"));
    UE_LOG(LogTemp, Log, TEXT("학생 이름이 변경 되었습니다: %s"), *Student->GetName());

    // 언리얼 엔진의 리플렉션 시스템으로 변수 수정
    FProperty *NameProp = UTeacher::StaticClass()->FindPropertyByName(TEXT("Name"));

    check(NameProp);

    FString NewTeacherName = TEXT("이득우");
    NameProp->SetValue_InContainer(Teacher, &NewTeacherName);

    FString CurrentTeacherName;
    NameProp->GetValue_InContainer(Teacher, &CurrentTeacherName);

    UE_LOG(LogTemp, Log, TEXT("강사 이름이 변경 되었습니다: %s"), *CurrentTeacherName);
    UE_LOG(LogTemp, Log, TEXT("---"));

    // 리플랙션 시스템으로 함수 호출
    UFunction *DoLessonTeacher = UTeacher::StaticClass()->FindFunctionByName(TEXT("DoLesson"));
    UFunction *DoLessonStudent = UStudent::StaticClass()->FindFunctionByName(TEXT("DoLesson"));

    check(DoLessonTeacher);
    check(DoLessonStudent);

    Teacher->ProcessEvent(DoLessonTeacher, nullptr);
    Student->ProcessEvent(DoLessonStudent, nullptr);
}