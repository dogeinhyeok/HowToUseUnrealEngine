#include "PackageExample.h"
#include "PackageObject.h"
#include "UObject/Package.h"
#include "UObject/SavePackage.h"


const FString UPackageExample::PackageName = TEXT("/Game/PackageExample");
const FString UPackageExample::AssetName = TEXT("PackageObject");

void UPackageExample::Init()
{
    SavePackageObject();
    LoadPackageObject();
}

void UPackageExample::SavePackageObject() const
{
    UPackage* Package = LoadPackage(nullptr, *PackageName, LOAD_None);
    if (Package) 
    { 
        Package->FullyLoad(); 
    }
    Package = CreatePackage(*PackageName);
    EObjectFlags ObjectFlag = RF_Public | RF_Standalone;

    UPackageObject* PackageObject = NewObject<UPackageObject>(Package, UPackageObject::StaticClass(), *AssetName, ObjectFlag);
    PackageObject->SetName(TEXT("이인혁"));
    PackageObject->SetOrder(36);

    const int32 NumOfSubObjects = 10;
    for (int32 i = 1; i < NumOfSubObjects; i++)
    {
        FString SubObjectName = FString::Printf(TEXT("SubObject%d"), i);
        UPackageObject* SubObject = NewObject<UPackageObject>(Package, *SubObjectName, ObjectFlag);
        SubObject->SetName(FString::Printf(TEXT("인혁%d"), i));
        SubObject->SetOrder(i);
    }

    const FString PackageFileName = FPackageName::LongPackageNameToFilename(
        PackageName, FPackageName::GetAssetPackageExtension()
    );

    FSavePackageArgs SaveArgs;
    SaveArgs.TopLevelFlags = ObjectFlag;
    SaveArgs.SaveFlags = SAVE_NoError;
    SaveArgs.bForceByteSwapping = false;
    SaveArgs.bWarnOfLongFilename = false;
    SaveArgs.bSlowTask = false;

    if(UPackage::SavePackage(Package, nullptr, *PackageFileName, SaveArgs))
    {
        FString StandardPath = PackageFileName;
        FPaths::MakeStandardFilename(StandardPath);
        UE_LOG(LogTemp, Log, TEXT("패키지 저장 성공: %s"), *StandardPath);
    }
}

void UPackageExample::LoadPackageObject() const
{
    UPackage* Package = LoadPackage(nullptr, *PackageName, LOAD_None);
    if (nullptr == Package)
    {
        UE_LOG(LogTemp, Error, TEXT("패키지 로드 실패: %s"), *PackageName);
        return;
    }

    Package->FullyLoad();

    UPackageObject* PackageObject = FindObject<UPackageObject>(Package, *AssetName);
    if (PackageObject)
    {
        UE_LOG(LogTemp, Log, TEXT("패키지 로드 성공: %s, %d"), *PackageObject->GetName(), PackageObject->GetOrder());
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("패키지 로드 실패: %s"), *PackageName); 
    }
}