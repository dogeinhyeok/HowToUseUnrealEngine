#include "SaveObject.h"


USaveObject::USaveObject()
{
    Order = -1;
    Name = TEXT("이인혁");
}

void USaveObject::Serialize(FArchive& Ar)
{
    Super::Serialize(Ar);

    Ar << Order;
    Ar << Name;
}
