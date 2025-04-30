#pragma once

#include "CoreMinimal.h"


class HOWTOUSEUNREALENGINE_API FNativeTrash
{
public:
	FNativeTrash(class UTrash* InTrash) : SafeTrash(InTrash) {}

	const class UTrash* GetTrash() const { return SafeTrash; }

private:
	class UTrash* SafeTrash = nullptr;
};