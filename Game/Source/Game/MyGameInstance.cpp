// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();
	// Custom initialization code here
	
	// 문자열 생성. 로그 메세지 출력 예시
	TCHAR LogCharArray[] = TEXT("MyGameInstance Initialized");
	UE_LOG(LogTemp, Log, TEXT("%s"), LogCharArray);

	// 언리얼 문자열 타입 사용.
	FString LogCharString = LogCharArray;
	UE_LOG(LogTemp, Log, TEXT("%s"), *LogCharString);
}
