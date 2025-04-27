#include "Creator.h"

UCreator::UCreator()
{
    CreatorName = TEXT("Unreal Creator");
    LatestContentTitle = TEXT("");
}

void UCreator::PublishNewContent(const FString& InContentTitle)
{
    LatestContentTitle = InContentTitle;
    OnContentPublished.Broadcast(CreatorName, LatestContentTitle);
}