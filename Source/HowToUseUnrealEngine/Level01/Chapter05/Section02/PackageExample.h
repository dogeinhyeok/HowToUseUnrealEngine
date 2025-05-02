#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"
#include "PackageExample.generated.h"


UCLASS( ClassGroup=(HowToUseUnrealEngine) )
class HOWTOUSEUNREALENGINE_API UPackageExample : public UGameInstance
{
	GENERATED_BODY()

public:
	UPackageExample();
	virtual void Init() override;
	void SavePackageObject() const;
	void LoadPackageObject() const;
	void LoadPackageObjectByPath() const;
	
	
private:
	static const FString PackageName;
	static const FString AssetName;
	FStreamableManager StreamableManager;
	TSharedPtr<FStreamableHandle> StreamableHandle;
};
