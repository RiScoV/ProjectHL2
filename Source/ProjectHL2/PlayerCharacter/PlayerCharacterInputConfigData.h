// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerCharacterInputConfigData.generated.h"

class UInputAction;

/**
 * 
 */
UCLASS()
class PROJECTHL2_API UPlayerCharacterInputConfigData : public UDataAsset
{
	GENERATED_BODY()
	
public :
	UPROPERTY(EditDefaultsOnly)
	UInputAction* InputMove;
	UPROPERTY(EditDefaultsOnly)
	UInputAction* InputJump;
	UPROPERTY(EditDefaultsOnly)
	UInputAction* InputCrouch;
	UPROPERTY(EditDefaultsOnly)
	UInputAction* InputSprint;
	UPROPERTY(EditDefaultsOnly)
	UInputAction* InputAttack;
	UPROPERTY(EditDefaultsOnly)
	UInputAction* InputLook;	// 주위 둘러보기
	UPROPERTY(EditDefaultsOnly)
	UInputAction* InputInteraction;	// 주위 둘러보기
};
