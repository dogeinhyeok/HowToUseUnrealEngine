#include "Platform.h"
#include "Creator.h"
#include "Subscriber.h"

void UPlatform::Print()
{
    // 크리에이터와 구독자 생성
    TObjectPtr<UCreator> Creator = NewObject<UCreator>(this);
    TObjectPtr<USubscriber> Subscriber = NewObject<USubscriber>(this);

    // 구독자가 크리에이터를 구독
    Subscriber->SubscribeToCreator(Creator);

    // 크리에이터가 새 콘텐츠를 게시
    Creator->PublishNewContent(TEXT("언리얼 콘텐츠"));

    // 구독자가 크리에이터를 구독해제
    Subscriber->UnsubscribeFromCreator(Creator);

    // 크리에이터가 새 콘텐츠를 게시
    Creator->PublishNewContent(TEXT("브이로그 콘텐츠"));
}