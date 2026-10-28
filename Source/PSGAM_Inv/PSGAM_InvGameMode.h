// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PSGAM_InvGameMode.generated.h"

/**
 *  Simple GameMode for a first person game
 */
UCLASS(abstract)
class APSGAM_InvGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APSGAM_InvGameMode();
};



