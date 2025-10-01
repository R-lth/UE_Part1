// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
    // 기본 값은 CDO라는 템플릿 객체 저장
    SchoolName = TEXT("기본 학교");
}

void UMyGameInstance::Init()
{
	Super::Init();
    // Custom initialization code here
    UE_LOG(LogTemp, Log, TEXT("======================="));

    // 클래스 정보.
    // 런타임 클래스 정보는 GetClass() 함수 사용.
    UClass* ClassRuntime = GetClass();
    UClass* ClassCompile = UMyGameInstance::StaticClass();

    // 두 타입 정보를 비교 후 결과 저장.
    FString Result
        = (ClassRuntime == ClassCompile) ? TEXT("같음") : TEXT("다름");

    // 결과 출력.
    UE_LOG(LogTemp, Log, TEXT("클래스 비교 결과: %s"), *Result);

    UE_LOG(LogTemp, Log, TEXT("======================="));

#pragma region 문자열 실습
    // 문자 배열 생성.
    // TCHAR LogCharArray[] = TEXT("Hello Unreal");
    // UE_LOG(LogTemp, Log, TEXT("%s"), LogCharArray);

    /*
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
    */
#pragma endregion

#pragma region FName
    /*
    // FName의 특징 살펴보기 (대소문자 구분없음)
    FName Key1(TEXT("PELVIS"));
    FName Key2(TEXT("pelvis"));

    // 비교 결과 확인
    FString Result = (Key1 == Key2) ? TEXT("Equal") : TEXT("Not Equal");
    UE_LOG(LogTemp, Log, TEXT("FName Comparison: %s"), *Result);

    // 값이 있는지 비교 (읽기 전용)
    for (int i = 0; i < 5; ++i)
    {
        // Name 풀에 검색하는 과정이 있기 때문에,
        // 반복 횟수가 많은 경우네느 부하가 클 수 있음.
        // static 키워드를 활용해서 부하를 줄이는 방법을 고려.
        const static FName Key = FName(FName(TEXT("pelvis")));
    }
    */
#pragma endregion
}
