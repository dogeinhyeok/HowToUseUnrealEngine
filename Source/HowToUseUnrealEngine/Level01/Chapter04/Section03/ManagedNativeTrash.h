#pragma once

#include "CoreMinimal.h"


class HOWTOUSEUNREALENGINE_API FManagedNativeTrash : public FGCObject
{
public:
	FManagedNativeTrash(class UTrash* InTrash) : SafeTrash(InTrash) {}

	// FGCObject 인터페이스 구현
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	virtual FString GetReferencerName() const override
	{
		return TEXT("FManagedNativeTrash");
	}

	const class UTrash* GetTrash() const { return SafeTrash; }

private:
	class UTrash* SafeTrash = nullptr;
};