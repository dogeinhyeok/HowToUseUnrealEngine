#include "PackageObject.h"


UPackageObject::UPackageObject()
{
    Order = -1;
    Name = TEXT("이인혁");
}

void UPackageObject::Serialize(FArchive& Ar)
{
    Super::Serialize(Ar);

    Ar << Order;
    Ar << Name;
}
