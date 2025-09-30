// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();
	// Custom initialization code here
	UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("MyGameInstance Initialized"));
}
