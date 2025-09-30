// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();
	// Custom initialization code here
    // 문자 배열 생성.
    TCHAR LogCharArray[] = TEXT("Hello Unreal");
    UE_LOG(LogTemp, Log, TEXT("%s"), LogCharArray);

#pragma region 문자열 실습
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
#pragma endregion

    // FName의 특징 살펴보기 (대소문자 구분없음)
    FName Key1(TEXT("PELVIS"));
	FName Key2(TEXT("pelvis"));

    // 비교 결과 확인
	FString Result = (Key1 == Key2) ? TEXT("Equal") : TEXT("Not Equal");
	UE_LOG(LogTemp, Log, TEXT("FName Comparison: %s"), *Result);

    // 값이 있는지 비교 (읽기 전용)
    for (int i =0; i < 5; ++i)
    {
        // Name 풀에 검색하는 과정이 있기 때문에,
        // 반복 횟수가 많은 경우네느 부하가 클 수 있음.
        // static 키워드를 활용해서 부하를 줄이는 방법을 고려.
        const static FName Key = FName(FName(TEXT("pelvis")));
	}
}
