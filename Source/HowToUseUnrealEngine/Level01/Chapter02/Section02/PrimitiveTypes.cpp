// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimitiveTypes.h"

// Sets default values
UPrimitiveTypes::UPrimitiveTypes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryComponentTick.bCanEverTick = true;

}

void UPrimitiveTypes::Print()
{
	TCHAR LogCharArray[] = TEXT("Hello Unreal");
	UE_LOG(LogTemp, Log, TEXT("%s"), LogCharArray);

	// FString LogString = LogCharArray;
	// UE_LOG(LogTemp, Log, TEXT("%s"), *LogString);

	// 문자열 배열 선언
	TArray<FString> Array;	
}
