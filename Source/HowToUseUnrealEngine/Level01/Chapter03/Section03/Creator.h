#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Creator.generated.h"

// 구독자에게 알림을 보내는 델리게이트 (블루프린트 노출)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCreatorUpdate, const FString&, CreatorName, const FString&, ContentTitle);

UCLASS(ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent))
class HOWTOUSEUNREALENGINE_API UCreator : public USceneComponent
{
    GENERATED_BODY()

public:
    UCreator();

    // 구독자들에게 새 콘텐츠 알림을 보내는 함수
    UFUNCTION(BlueprintCallable, Category = "Level01|Chapter03|Section03")
    void PublishNewContent(const FString& InContentTitle);

    // Getter 함수들
    UFUNCTION(BlueprintPure, Category = "Level01|Chapter03|Section03")
    FString GetCreatorName() const { return CreatorName; }

    UFUNCTION(BlueprintPure, Category = "Level01|Chapter03|Section03")
    FString GetLatestContentTitle() const { return LatestContentTitle; }

    // 구독자에게 알림을 보내는 델리게이트
    FOnCreatorUpdate OnContentPublished;

private:
    UPROPERTY()
    FString CreatorName;

    UPROPERTY()
    FString LatestContentTitle;
};