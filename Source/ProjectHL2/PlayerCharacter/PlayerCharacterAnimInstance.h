// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerCharacterAnimInstance.generated.h"


class UCharacterTrajectoryComponent;
class UCharacterMovementComponent;
class APlayerCharacter;

/**
 * 
 */
UCLASS()
class PROJECTHL2_API UPlayerCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


protected:
	virtual void NativeUpdateAnimation(float _deltaSeconds) override;
	
private :
	UPROPERTY(EditAnyWhere, BluePrintReadOnly, Category = Variables, Meta = (AllowPrivateAccess = true))
	float walkSpeed;
	UPROPERTY(EditAnyWhere, BluePrintReadOnly, Category = Variables, Meta = (AllowPrivateAccess = true))
	bool isMovingOnGround;
	UPROPERTY(EditAnyWhere, BluePrintReadOnly, Category = Variables, Meta = (AllowPrivateAccess = true))
	bool isFalling;
	UPROPERTY(EditAnyWhere, BluePrintReadOnly, Category = Variables, Meta = (AllowPrivateAccess = true))
	bool isFlying;
	UPROPERTY(EditAnyWhere, BluePrintReadOnly, Category = Variables, Meta = (AllowPrivateAccess = true))
	bool isSwimming;
	UPROPERTY(EditAnyWhere, BluePrintReadOnly, Category = Variables, Meta = (AllowPrivateAccess = true))
	bool isCrouching;
	UPROPERTY(EditAnyWhere, BluePrintReadOnly, Category = Variables, Meta = (AllowPrivateAccess = true))
	FVector Velocity;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Variables, Meta = (AllowPrivateAccess = true))
	UCharacterMovementComponent* CharacterMovementComponent;
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Variables, Meta = (AllowPrivateAccess = true))
	UCharacterTrajectoryComponent* CharacterTrajectoryComponent;
};
