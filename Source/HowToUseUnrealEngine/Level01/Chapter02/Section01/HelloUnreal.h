// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HelloUnreal.generated.h"

UCLASS()
class HOWTOUSEUNREALENGINE_API AHelloUnreal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHelloUnreal();

	// "HelloUnreal"을 출력하는 함수
	UFUNCTION(BlueprintCallable, Category = "Level01|Chapter02|Section01")
	void PrintHello();
};
