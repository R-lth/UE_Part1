// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();
	// Custom initialization code here
    // 문자 배열 생성.
    TCHAR LogCharArray[] = TEXT("Hello Unreal");
    UE_LOG(LogTemp, Log, TEXT("%s"), LogCharArray);

    // 언리얼 문자열 타입 사용.
    FString LogCharString = LogCharArray;
    UE_LOG(LogTemp, Log, TEXT("%s"), *LogCharString);
    
    // FString에서 TCHAR를 가져오는 방법.
    const TCHAR* LogCharPointer = *LogCharString;
    TCHAR* LogCharDataPointer = LogCharString.GetCharArray().GetData();
    UE_LOG(LogTemp, Log, TEXT("%s"), LogCharPointer);

    // 문자열 복사.
    TCHAR LogCharArrayWithSize[100] = {};
    //strcpy_s()
    FCString::Strcpy(
        LogCharArrayWithSize,
        LogCharString.Len(),
        *LogCharString
    );

    UE_LOG(LogTemp, Log, TEXT("%s"), LogCharArrayWithSize);

    // 변환.
    int32 IntValue = 32;
    float FloatValue = 3.141592f;

    // 문자열 조합 함수 활용.
    FString FloatIntString = FString::Printf(
        TEXT("Int: %d, Float: %f"), IntValue, FloatValue
    );

    UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);

    // 개별 숫자를 문자열로 변환하는 함수 활용.
    FString FloatString = FString::SanitizeFloat(FloatValue);
    FString IntString = FString::FromInt(IntValue);

    UE_LOG(
        LogTemp,
        Log,
        TEXT("FloatString: %s, IntString: %s"),
        *FloatString,
        *IntString
    );
}
