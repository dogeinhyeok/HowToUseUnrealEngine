#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABFountain.generated.h"


UCLASS()
class HOWTOUSEUNREALENGINE_API AABFountain : public AActor
{
	GENERATED_BODY()
	
public:	
	AABFountain();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<class UStaticMeshComponent> Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<class UStaticMeshComponent> Water;
};