// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AwakenGameModeBase.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class AWAKEN_API AKillEmAllGameMode : public AAwakenGameModeBase
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
    virtual void PawnKilled(APawn* PawnKilled) override;

private:
void EndGame (bool BIsPlayerWinner);


};
