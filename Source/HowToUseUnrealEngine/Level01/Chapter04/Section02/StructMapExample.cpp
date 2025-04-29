#include "StructMapExample.h"

FString MakeRandomName()
{
    TCHAR FirstChar[] = TEXT("김이박최");
    TCHAR MiddleChar[] = TEXT("상인지성");
    TCHAR LastChar[] = TEXT("수혁원연");

    TArray<TCHAR> RandomArray;
    RandomArray.SetNum(3);

    RandomArray[0] = FirstChar[FMath::RandRange(0, 3)];
    RandomArray[1] = MiddleChar[FMath::RandRange(0, 3)];
    RandomArray[2] = LastChar[FMath::RandRange(0, 3)];

    return RandomArray.GetData();
}

void UStructMapExample::Print()
{
	const int32 StudentNum = 300;

    // Struct 학생 데이터 생성
    for (int32 i = 0; i < StudentNum; i++)
    {
        StudentsData.Emplace(FStudentData(MakeRandomName(), i));
    }

    // Struct는 STL 컨테이너처럼 알고리즘 함수(Algo::Transform 등)를 사용할 수 있습니다.

    // 모든 학생 이름의 수
    TArray<FString> AllStudentNames;
    Algo::Transform(StudentsData, AllStudentNames, 
        [](const FStudentData& Val) { return Val.Name; }
    );

    UE_LOG(LogTemp, Log, TEXT("모든 학생 이름의 수: %d"), AllStudentNames.Num());

    // 중복 없는 모든 학생 이름의 수
    TSet<FString> AllUniqueNames;
    Algo::Transform(StudentsData, AllUniqueNames, 
        [](const FStudentData& Val) { return Val.Name; }
    );

    UE_LOG(LogTemp, Log, TEXT("중복 없는 모든 학생 이름의 수: %d"), AllUniqueNames.Num());

    // 순번에 따른 TMap 데이터 생성
    for (const FStudentData& Data : StudentsData)
    {
        StudentsMap.Add(Data.Order, Data.Name);
    }

    UE_LOG(LogTemp, Log, TEXT("순번에 따른 학생 맵의 레코드 수: %d"), StudentsMap.Num());

    // 이름에 따른 TMap 데이터 생성
    TMap<FString, int32> StudentsMapByUniqueName;
    for (const auto& Pair : StudentsMap)
    {
        StudentsMapByUniqueName.Add(Pair.Value, Pair.Key);
    }

    UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 맵의 레코드 수: %d"), StudentsMapByUniqueName.Num());

    // 이름에 따른 TMultiMap(중복허용) 데이터 생성
    TMultiMap<FString, int32> StudentsMapByName;
    for (const auto& Pair : StudentsMap)
    {
        StudentsMapByName.Add(Pair.Value, Pair.Key);
    }

    UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 멀티맵의 레코드 수: %d"), StudentsMapByName.Num());

    // 특정 이름이 몇 명인지 찾기
    const FString TargetName = TEXT("이인혁");
    TArray<int32> TargetStudentOrders;
    StudentsMapByName.MultiFind(TargetName, TargetStudentOrders);

    UE_LOG(LogTemp, Log, TEXT("이름에 %s인 학생 수: %d"), *TargetName, TargetStudentOrders.Num());
}