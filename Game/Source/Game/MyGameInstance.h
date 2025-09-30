// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
private:
	virtual void Init() override;
};
