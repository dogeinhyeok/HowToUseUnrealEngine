#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Subscriber.generated.h"

UCLASS(ClassGroup=(HowToUseUnrealEngine), meta=(BlueprintSpawnableComponent))
class HOWTOUSEUNREALENGINE_API USubscriber : public USceneComponent
{
    GENERATED_BODY()

public:
    USubscriber();

    // 크리에이터 구독 함수
    UFUNCTION(BlueprintCallable, Category = "Level01|Chapter03|Section03")
    void SubscribeToCreator(class UCreator* Creator);

    // 구독 해제 함수
    UFUNCTION(BlueprintCallable, Category = "Level01|Chapter03|Section03")
    void UnsubscribeFromCreator(class UCreator* Creator);

    // 새 콘텐츠 알림을 받는 함수
    UFUNCTION(BlueprintCallable, Category = "Level01|Chapter03|Section03")
    void OnNewContent(const FString& CreatorName, const FString& ContentTitle);

private:
    // 구독 중인 크리에이터 목록
    UPROPERTY()
    TArray<class UCreator*> SubscribedCreators;

    // 구독자 이름
    UPROPERTY()
    FString SubscriberName;
}; 