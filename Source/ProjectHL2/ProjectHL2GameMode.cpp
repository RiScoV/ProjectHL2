// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectHL2GameMode.h"
#include "ProjectHL2Character.h"
#include "UObject/ConstructorHelpers.h"

AProjectHL2GameMode::AProjectHL2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
