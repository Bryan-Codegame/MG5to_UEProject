// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MgfpsGameMode.generated.h"

UCLASS(minimalapi)
class AMgfpsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMgfpsGameMode();
	
	void CompleteMission(APawn* Pawn);

	UFUNCTION(BlueprintImplementableEvent, Category="GameMode")
	void OnMissionCompleted(APawn* Pawn);
	
};



