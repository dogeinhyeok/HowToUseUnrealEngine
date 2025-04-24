// Fill out your copyright notice in the Description page of Project Settings.


#include "HelloUnreal.h"

// 문자열 상수 정의
const FString MESSAGE_TEXT = TEXT("HelloUnreal");

// Sets default values
AHelloUnreal::AHelloUnreal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// "HelloUnreal"을 출력하는 함수
void AHelloUnreal::PrintHello()
{
	// 로그에 출력
	UE_LOG(LogTemp, Log, TEXT("%s"), *MESSAGE_TEXT);
	
	// 화면에 출력 (5초 동안, 빨간색으로)
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, *MESSAGE_TEXT);
	}
}

