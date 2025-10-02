// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"

UMyGameInstance::UMyGameInstance()
{
	// 기본 값은 CDO라는 템플릿 객체에 저장.
	SchoolName = TEXT("기본학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("======================="));

	// 클래스 정보.
	// 런타임 클래스 정보는 GetClass() 함수 사용.
	UClass* ClassRuntime = GetClass();
	UClass* ClassCompile = UMyGameInstance::StaticClass();

	// 어서트 (Assert).
	//check(ClassRuntime != ClassCompile);
	//ensure(ClassRuntime != ClassCompile);
	//ensureAlways(ClassRuntime != ClassCompile);
	//ensureMsgf(ClassRuntime != ClassCompile, TEXT("일부러 발생시킨 오류"));


	// 두 타입 정보를 비교 후 결과 저장.
	FString Result
		= (ClassRuntime == ClassCompile) ? 
		TEXT("같음") : TEXT("다름");

	// 결과 출력.
	UE_LOG(LogTemp, Log, TEXT("클래스 비교 결과: %s"), *Result);

	// 클래스 이름 출력.
	UE_LOG(
		LogTemp,
		Log,
		TEXT("학교를 담당하는 클래스 이름: %s"),
		*ClassRuntime->GetName()
	);

	// 값 출력.
	SchoolName = TEXT("포텐업");

	UE_LOG(LogTemp, Log, TEXT("학교 이름: %s"), *SchoolName);
	UE_LOG(LogTemp, Log, TEXT("학교 이름 기본값: %s"), 
		*GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName);

	UE_LOG(LogTemp, Log, TEXT("======================="));

	// 학생 / 선생님 객체 생성.
	UStudent* Student = NewObject<UStudent>();
	UTeacher* Teacher = NewObject<UTeacher>();

	// 학생 클래스의 Getter/Setter 사용.
	Student->SetName(TEXT("학생1"));
	UE_LOG(LogTemp, Log, 
		TEXT("새로운 학생 이름: %s"), 
		*Student->GetName()
	);

	// 언리얼의 리플렉션 시스템을 활용해 프로퍼티 사용.
	FString CurrentTeacherName;
	FString NewTeacherName(TEXT("존카멕"));
	FProperty* NameProperty
		= UTeacher::StaticClass()->FindPropertyByName(TEXT("Name"));
	if (NameProperty /*!= nullptr*/)
	{
		NameProperty->GetValue_InContainer(
			Teacher, &CurrentTeacherName
		);

		UE_LOG(LogTemp, Log, 
			TEXT("현재 선생님 이름: %s"), 
			*CurrentTeacherName
		);

		NameProperty->SetValue_InContainer(
			Teacher,
			&NewTeacherName
		);

		UE_LOG(LogTemp, Log,
			TEXT("새로운 선생님 이름: %s"),
			*Teacher->GetName()
		);
	}

	UE_LOG(LogTemp, Log, TEXT("======================="));

	// 함수 호출.
	Student->DoLesson();

	// 리플렉션을 활용한 함수 호출.
	UFunction* DoLessionFunction
		= Teacher->GetClass()->FindFunctionByName(TEXT("DoLesson"));
	if (DoLessionFunction)
	{
		Teacher->ProcessEvent(DoLessionFunction, nullptr);
	}

	UE_LOG(LogTemp, Log, TEXT("======================="));
}
