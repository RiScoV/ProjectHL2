// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UCharacterTrajectoryComponent;
class UCharacterMovementComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class PROJECTHL2_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();
protected :
	virtual void PostInitializeComponents() override;
	
public :
	UCharacterMovementComponent* GetCharMovement() const
	{
		UCharacterMovementComponent* movement = GetCharacterMovement();
		check(movement);
		return movement;
	}
	UCharacterTrajectoryComponent* GetCharacterTrajectoryComponent() const
	{
		check(MotionMatching);
		return MotionMatching;
	}
	
public:
	// DefaultPawn 에서 발췌
	void Move(FVector2D moveVec);
	void Look(FVector2D lookVec);
	void ToggleCrouch();
	void Sprint();
	void UnSprint();
	void Jump();
	void StopJumping();
	void Interaction();
	void Attack();

private :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Camera", meta=(AllowPrivateAccess="true"))
	USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta=(AllowPrivateAccess="true"))
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterTrajectory", meta=(AllowPrivateAccess="true"))
	UCharacterTrajectoryComponent* MotionMatching;
};
