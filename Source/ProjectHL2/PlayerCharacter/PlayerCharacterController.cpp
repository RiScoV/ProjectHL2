// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "PlayerCharacterInputConfigData.h"

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Get LocalPlayer SubSystem, check
	UEnhancedInputLocalPlayerSubsystem* subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(subSystem);
	// Clear and Add Mapping
	subSystem->ClearAllMappings();
	subSystem->AddMappingContext(_inputMapping, 0);
	// Get InputSystem > EnhancedInputSystem
	UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(InputComponent);
	check(PEI);
	
	// Bind Action
	PEI->BindAction(_inputAction->InputMove, ETriggerEvent::Triggered, this, &APlayerCharacterController::Move);
	PEI->BindAction(_inputAction->InputLook, ETriggerEvent::Triggered, this, &APlayerCharacterController::Look);
	PEI->BindAction(_inputAction->InputJump, ETriggerEvent::Started, this, &APlayerCharacterController::Jump);
	PEI->BindAction(_inputAction->InputJump, ETriggerEvent::Completed, this, &APlayerCharacterController::StopJumping);
	PEI->BindAction(_inputAction->InputSprint, ETriggerEvent::Started, this, &APlayerCharacterController::Sprint);
	PEI->BindAction(_inputAction->InputSprint, ETriggerEvent::Completed, this, &APlayerCharacterController::StopSprint);
	PEI->BindAction(_inputAction->InputCrouch, ETriggerEvent::Started, this, &APlayerCharacterController::Crouch);
	PEI->BindAction(_inputAction->InputAttack, ETriggerEvent::Started, this, &APlayerCharacterController::Attack);
	PEI->BindAction(_inputAction->InputInteraction, ETriggerEvent::Started, this, &APlayerCharacterController::Interaction);
}
void APlayerCharacterController::Move(const FInputActionValue& Value)
{
	GetPlayerCharacter()->Move(Value.Get<FVector2d>());
}
void APlayerCharacterController::Look(const FInputActionValue& Value)
{
	GetPlayerCharacter()->Look(Value.Get<FVector2d>());
}
void APlayerCharacterController::Jump(const FInputActionValue& Value)
{
	GetPlayerCharacter()->Jump();
}
void APlayerCharacterController::StopJumping(const FInputActionValue& Value)
{
	GetPlayerCharacter()->StopJumping();
}

void APlayerCharacterController::Sprint(const FInputActionValue& Value)
{
	GetPlayerCharacter()->Sprint();
}
void APlayerCharacterController::StopSprint(const FInputActionValue& Value)
{
	GetPlayerCharacter()->UnSprint();
}
void APlayerCharacterController::Crouch(const FInputActionValue& Value)
{
	GetPlayerCharacter()->ToggleCrouch();
}
void APlayerCharacterController::Attack(const FInputActionValue& Value)
{
	GetPlayerCharacter()->Attack();
}
void APlayerCharacterController::Interaction(const FInputActionValue& Value)
{
	GetPlayerCharacter()->Interaction();
}
