#include "SerializationJsonExample.h"
#include "SaveData.h"
#include "SaveObject.h"
#include "JsonObjectConverter.h"


void USerializationJsonExample::Init()
{
	Super::Init();

    // Saved/SaveGames 경로
    FString SaveDir = FPaths::Combine(FPaths::ProjectUserDir(), TEXT("Saved"), TEXT("SaveGames"));
    FPaths::MakeStandardFilename(SaveDir);
    UE_LOG(LogTemp, Log, TEXT("SaveDir: %s"), *SaveDir);

    // SaveData.json 경로
    FString SaveDataDir = FPaths::Combine(*SaveDir, TEXT("SaveData.json"));
    UE_LOG(LogTemp, Log, TEXT("SaveDataDir: %s"), *SaveDataDir);

    // 파일 쓰기 객체 생성
    FString JsonOutputString;
    FSaveData SaveDataSrc(16, TEXT("이인혁"));
    TSharedRef<FJsonObject> JsonObjectSrc = MakeShared<FJsonObject>();
    FJsonObjectConverter::UStructToJsonObject(FSaveData::StaticStruct(), &SaveDataSrc, JsonObjectSrc);
    
    // Json 파일 쓰기
    TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<TCHAR>::Create(&JsonOutputString);
    if(FJsonSerializer::Serialize(JsonObjectSrc, JsonWriter))
    {
        FFileHelper::SaveStringToFile(JsonOutputString, *SaveDataDir);
    }

    // 파일 읽기 객체
    FString JsonInputString;
    TSharedPtr<FJsonObject> JsonObjectPtr;
    FFileHelper::LoadFileToString(JsonInputString, *SaveDataDir);

    // Json 파일 읽기
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonInputString);
    if(FJsonSerializer::Deserialize(JsonReader, JsonObjectPtr))
    {
        USaveObject* LoadedObject = NewObject<USaveObject>();
        FJsonObjectConverter::JsonObjectToUStruct(JsonObjectPtr.ToSharedRef(), LoadedObject->GetClass(), LoadedObject);
        UE_LOG(LogTemp, Log, TEXT("JsonData: %d, %s"), LoadedObject->GetOrder(), *LoadedObject->GetName());
    }
}