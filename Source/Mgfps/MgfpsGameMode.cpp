// Copyright Epic Games, Inc. All Rights Reserved.

#include "MgfpsGameMode.h"
#include "MgfpsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMgfpsGameMode::AMgfpsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void AMgfpsGameMode::CompleteMission(APawn* Pawn)
{
	if (Pawn)
	{
		Pawn->DisableInput(nullptr);
	}

	//Show UI Mission Complete by AddToViewport
	OnMissionCompleted(Pawn);
}
