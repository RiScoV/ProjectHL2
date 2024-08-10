// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class UPlayerCharacterInputConfigData;

/**
 * 
 */
UCLASS()
class PROJECTHL2_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()
	
	// 기능 영역
#pragma region Input
protected:
	virtual void SetupInputComponent() override;

private :
	APlayerCharacter* GetPlayerCharacter() const
	{
		APlayerCharacter* playerCharacter = CastChecked<APlayerCharacter>(GetCharacter());
		check(playerCharacter);
		return playerCharacter;
	}
	
private :
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EnhancedInput", meta=(AllowPrivateAccess="true"))
	UInputMappingContext* _inputMapping;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EnhancedInput", meta=(AllowPrivateAccess="true"))
	UPlayerCharacterInputConfigData* _inputAction;

public :
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Jump(const FInputActionValue& Value);
	void StopJumping(const FInputActionValue& Value);
	void Sprint(const FInputActionValue& Value);
	void StopSprint(const FInputActionValue& Value);
	void Crouch(const FInputActionValue& Value);
	void Attack(const FInputActionValue& Value);
	void Interaction(const FInputActionValue& Value);
#pragma endregion
};
