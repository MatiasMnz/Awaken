// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AwakenGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class AWAKEN_API AAwakenGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    virtual void PawnKilled(APawn* PawnKilled);
};
