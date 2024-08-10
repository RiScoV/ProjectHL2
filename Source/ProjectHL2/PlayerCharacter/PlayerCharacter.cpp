// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "CharacterTrajectoryComponent.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MotionMatching = CreateDefaultSubobject<UCharacterTrajectoryComponent>(TEXT("CharacterTrajectoryComponent"));
	
	// Create a camera boom (pulls in towards the player if there is a collision)
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	// Create a follow camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
}
void APlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void APlayerCharacter::Move(FVector2D moveVec)
{
	if(Controller == nullptr)
		return;
	
	// find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	// get forward vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	// get right vector 
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// add movement 
	AddMovementInput(ForwardDirection, moveVec.Y);
	AddMovementInput(RightDirection, moveVec.X);
}
void APlayerCharacter::Look(FVector2D lookVec)
{
	if(Controller == nullptr)
		return;
	
	// add yaw and pitch input to controller
	AddControllerYawInput(lookVec.X);
	AddControllerPitchInput(lookVec.Y);
}
void APlayerCharacter::ToggleCrouch()
{
	if(bIsCrouched)
		UnCrouch();
	else
		Crouch();
}
void APlayerCharacter::Sprint()
{
	GetCharMovement()->MaxWalkSpeed = 600.0f;
}
void APlayerCharacter::UnSprint()
{
	GetCharMovement()->MaxWalkSpeed = 400.0f;
}
void APlayerCharacter::Jump()
{
	if(!CanJump())
		return;
		
	Super::Jump();
}
void APlayerCharacter::StopJumping()
{
	Super::StopJumping();
}

void APlayerCharacter::Interaction()
{
}
void APlayerCharacter::Attack()
{
}