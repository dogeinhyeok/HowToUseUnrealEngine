#include "SerializationExample.h"
#include "SaveData.h"
#include "SaveObject.h"


void USerializationExample::Init()
{
	Super::Init();

    // Saved/SaveGames 경로
    FString SaveDir = FPaths::Combine(FPaths::ProjectUserDir(), TEXT("Saved"), TEXT("SaveGames"));
    FPaths::MakeStandardFilename(SaveDir);
    UE_LOG(LogTemp, Log, TEXT("SaveDir: %s"), *SaveDir);

    // SaveData.bin 경로
    const FString SaveFileDir = FPaths::Combine(*SaveDir, TEXT("SaveData.bin"));
    UE_LOG(LogTemp, Log, TEXT("SaveDataDir: %s"), *SaveFileDir);

    // 파일 쓰기 객체 생성
    FSaveData SaveDataSrc(16, TEXT("이인혁"));
    FArchive* WriteSaveDataArchive = IFileManager::Get().CreateFileWriter(*SaveFileDir);

    // 파일 쓰기
    if (WriteSaveDataArchive != nullptr)
    {
        *WriteSaveDataArchive << SaveDataSrc;
        WriteSaveDataArchive->Close();

        // 파일 쓰기 객체 제거
        delete WriteSaveDataArchive;
        WriteSaveDataArchive = nullptr;
    }
    
    // 파일 읽기 객체 생성
    FSaveData SaveDataDest;
    FArchive* ReadSaveDataArchive = IFileManager::Get().CreateFileReader(*SaveFileDir);

    // 파일 읽기
    if (ReadSaveDataArchive != nullptr)
    {
        *ReadSaveDataArchive << SaveDataDest;
        ReadSaveDataArchive->Close();

        // 파일 읽기 객체 제거
        delete ReadSaveDataArchive;
        ReadSaveDataArchive = nullptr;

        UE_LOG(LogTemp, Log, TEXT("SaveData: %d, %s"), SaveDataDest.Order, *SaveDataDest.Name);
    }

    // UObject 생성 및 초기화
    SaveObject = NewObject<USaveObject>();
    SaveObject->SetOrder(59);
    SaveObject->SetName(TEXT("이상한"));

    // 오브젝트 데이터 저장 경로 설정
    FString SaveObjectFile = FPaths::Combine(*SaveDir, TEXT("SaveObject.bin"));
    FPaths::MakeStandardFilename(SaveObjectFile);
    UE_LOG(LogTemp, Log, TEXT("ObjectDataDir: %s"), *SaveObjectFile);

    // 메모리 버퍼에 사용할 직렬화 객체 생성
    TArray<uint8> SaveObjectBuffer;
    FMemoryWriter MemoryWriter(SaveObjectBuffer);
    SaveObject->Serialize(MemoryWriter);

    // 메모리 버퍼를 파일에 쓰기
    if(TUniquePtr<FArchive> WriteSaveObjectArchive = TUniquePtr<FArchive>(IFileManager::Get().CreateFileWriter(*SaveObjectFile)))
    {
        *WriteSaveObjectArchive << SaveObjectBuffer;
        WriteSaveObjectArchive->Close();
    }

    // 메모리 버퍼를 읽어올 직렬화 객체 생성
    FMemoryReader MemoryReader(SaveObjectBuffer);
    USaveObject* SaveObjectDest = NewObject<USaveObject>();
    SaveObjectDest->Serialize(MemoryReader);

    UE_LOG(LogTemp, Log, TEXT("ObjectData: %d, %s"), SaveObjectDest->GetOrder(), *SaveObjectDest->GetName());
}