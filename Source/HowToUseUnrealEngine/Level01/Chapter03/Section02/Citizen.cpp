#include "Citizen.h"
#include "CitizenCard.h"

UCitizen::UCitizen()
{
    CitizenCard = CreateDefaultSubobject<UCitizenCard>(TEXT("CitizenCard"));
}

