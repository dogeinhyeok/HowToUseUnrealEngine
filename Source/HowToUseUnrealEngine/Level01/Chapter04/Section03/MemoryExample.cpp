#include "MemoryExample.h"
#include "Trash.h"
#include "NativeTrash.h"
#include "ManagedNativeTrash.h"


void CheckUObjectIsValid(const UObject* InObject, const FString& InTag)
{
    if(InObject->IsValidLowLevel())
    {
        UE_LOG(LogTemp, Log, TEXT("[%s] ObjectExists"), *InTag);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("[%s] ObjectDestroyed"), *InTag);
    }
}

void CheckUObjectIsNull(const UObject* InObject, const FString& InTag)
{
    if(InObject == nullptr)
    {
        UE_LOG(LogTemp, Log, TEXT("[%s] PointerIsNull"), *InTag);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("[%s] PointerExists"), *InTag);
    }
}

void UMemoryExample::Init()
{
    Super::Init();

    NonPropTrash = NewObject<UTrash>(this, UTrash::StaticClass());
    PropTrash = NewObject<UTrash>(this, UTrash::StaticClass());

    NonPropTrashArray.Add(NewObject<UTrash>(this, UTrash::StaticClass()));
    PropTrashArray.Add(NewObject<UTrash>(this, UTrash::StaticClass()));

    NativeTrash = new FNativeTrash(NewObject<UTrash>(this, UTrash::StaticClass()));
    ManagedNativeTrash = new FManagedNativeTrash(NewObject<UTrash>(this, UTrash::StaticClass()));
}


void UMemoryExample::Shutdown()
{
    Super::Shutdown();

    // 비프로퍼티 객체는 가비지 컬렉터가 추적하지 않아 댕글링 포인터 발생
    CheckUObjectIsNull(NonPropTrash, TEXT("NonPropTrash"));
    CheckUObjectIsValid(NonPropTrash, TEXT("NonPropTrash"));

    UE_LOG(LogTemp, Log, TEXT("---"));

    // 프로퍼티 객체는 가비지 컬렉터가 추적하여 댕글링 포인터 발생하지 않음
    CheckUObjectIsNull(PropTrash, TEXT("PropTrash"));
    CheckUObjectIsValid(PropTrash, TEXT("PropTrash"));

    UE_LOG(LogTemp, Log, TEXT("---"));

    // 비프로퍼티 배열 또한 가비지 컬렉터가 추적하지 않아 댕글링 포인터 발생
    CheckUObjectIsNull(NonPropTrashArray[0], TEXT("NonPropTrashArray[0]"));
    CheckUObjectIsValid(NonPropTrashArray[0], TEXT("NonPropTrashArray[0]"));

    UE_LOG(LogTemp, Log, TEXT("---"));

    // 프로퍼티 배열 또한 가비지 컬렉터가 추적하여 댕글링 포인터 발생하지 않음
    CheckUObjectIsNull(PropTrashArray[0], TEXT("PropTrashArray[0]"));
    CheckUObjectIsValid(PropTrashArray[0], TEXT("PropTrashArray[0]"));

    UE_LOG(LogTemp, Log, TEXT("---"));

    // 네이티브 객체 또한 가비지 컬렉터가 추적하지 않아 댕글링 포인터 발생
    const UTrash* NativeInnerTrash = NativeTrash->GetTrash();

    delete NativeTrash;
    NativeTrash = nullptr;

    CheckUObjectIsNull(NativeInnerTrash, TEXT("NativeInnerTrash"));
    CheckUObjectIsValid(NativeInnerTrash, TEXT("NativeInnerTrash"));

    UE_LOG(LogTemp, Log, TEXT("---"));

    // 관리되는 네이티브 객체는 가비지 컬렉터가 추적하여 댕글링 포인터 발생하지 않음
    const UTrash* ManagedNativeInnerTrash = ManagedNativeTrash->GetTrash();

    delete ManagedNativeTrash;
    ManagedNativeTrash = nullptr;

    CheckUObjectIsNull(ManagedNativeInnerTrash, TEXT("ManagedNativeInnerTrash"));
    CheckUObjectIsValid(ManagedNativeInnerTrash, TEXT("ManagedNativeInnerTrash"));
}