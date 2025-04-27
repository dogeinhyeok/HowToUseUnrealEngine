#include "Subscriber.h"
#include "Creator.h"

USubscriber::USubscriber()
{
    SubscriberName = TEXT("Unreal Subscriber");
}

void USubscriber::SubscribeToCreator(UCreator* Creator)
{
    if (Creator && !SubscribedCreators.Contains(Creator))
    {
        // 구독한 크리에이터 목록에 추가하고 델리게이트 연결
        SubscribedCreators.Add(Creator);
        Creator->OnContentPublished.AddDynamic(this, &USubscriber::OnNewContent);
        UE_LOG(LogTemp, Log, TEXT("%s가 %s를 구독했습니다."), *SubscriberName, *Creator->GetCreatorName());
    }
}

void USubscriber::UnsubscribeFromCreator(UCreator* Creator)
{
    if (Creator && SubscribedCreators.Contains(Creator))
    {
        // 구독 해제한 크리에이터 목록에서 제거하고 델리게이트 해제
        SubscribedCreators.Remove(Creator);
        Creator->OnContentPublished.RemoveDynamic(this, &USubscriber::OnNewContent);
        UE_LOG(LogTemp, Log, TEXT("%s가 %s의 구독을 해제했습니다."), *SubscriberName, *Creator->GetCreatorName());
    }
}

void USubscriber::OnNewContent(const FString& CreatorName, const FString& ContentTitle)
{
    // 새 콘텐츠 알림 로그 출력
    UE_LOG(LogTemp, Log, TEXT("%s가 새 콘텐츠를 업로드 했습니다: %s"), *CreatorName, *ContentTitle);
} 