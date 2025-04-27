# include "City.h"
# include "Citizen.h"
# include "CitizenCard.h"

void UCity::Print()
{
    // 시민 배열 선언
    TArray<UCitizen*> Citizens;

    // 4명의 시민 생성
    for (int32 i = 0; i < 4; ++i)
    {
        // 새로운 시민 생성
        UCitizen* NewCitizen = NewObject<UCitizen>(this);
        NewCitizen->RegisterComponent();
        
        // 시민증에 직업 할당
        UCitizenCard* Card = NewCitizen->GetCitizenCard();
        switch (i)
        {
            case 0:
                Card->SetJob(EJob::Unemployed);
                break;
            case 1:
                Card->SetJob(EJob::Farmer);
                break;
            case 2:
                Card->SetJob(EJob::Builder);
                break;
            case 3:
                Card->SetJob(EJob::Doctor);
                break;
        }
        
        // 시민을 배열에 추가
        Citizens.Add(NewCitizen);
    }

    // 각 시민의 정보 출력
    for (UCitizen* Citizen : Citizens)
    {
        UCitizenCard* Card = Citizen->GetCitizenCard();
        FString JobName = StaticEnum<EJob>()->GetNameStringByValue(static_cast<int64>(Card->GetJob()));
        UE_LOG(LogTemp, Log, TEXT("시민의 직업: %s"), *JobName);
    }
}