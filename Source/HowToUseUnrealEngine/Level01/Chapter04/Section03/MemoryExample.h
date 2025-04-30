#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MemoryExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine))
class HOWTOUSEUNREALENGINE_API UMemoryExample : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	virtual void Shutdown() override;

private:
	TObjectPtr<class UTrash> NonPropTrash;

	UPROPERTY()
	TObjectPtr<class UTrash> PropTrash;

	TArray<TObjectPtr<class UTrash>> NonPropTrashArray;

	UPROPERTY()
	TArray<TObjectPtr<class UTrash>> PropTrashArray;

	class FNativeTrash *NativeTrash = nullptr;

	class FManagedNativeTrash *ManagedNativeTrash = nullptr;
};