// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterAnimInstance.h"
#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CharacterTrajectoryComponent.h"


void UPlayerCharacterAnimInstance::NativeUpdateAnimation(float _deltaSeconds)
{
	Super::NativeUpdateAnimation(_deltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn))
	{
		APlayerCharacter* character = CastChecked<APlayerCharacter>(Pawn);
		check(character);
		Velocity = character->GetVelocity();
		walkSpeed = character->GetVelocity().Size();

		CharacterMovementComponent = character->GetCharMovement();
		check(CharacterMovementComponent);
		isFalling = CharacterMovementComponent->IsFalling();
		isFlying = CharacterMovementComponent->IsFlying();
		isCrouching = CharacterMovementComponent->IsCrouching();
		isSwimming = CharacterMovementComponent->IsSwimming();
		isMovingOnGround = CharacterMovementComponent->IsMovingOnGround();

		CharacterTrajectoryComponent = character->GetCharacterTrajectoryComponent();
	}
}
