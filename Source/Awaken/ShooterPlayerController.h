// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AWAKEN_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;
	void RemoveWidget();
	UUserWidget* MisionRequest;
    
	protected:
	virtual void BeginPlay() override;

    private:

    UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;

	UPROPERTY(EditAnywhere)
    TSubclassOf<class UUserWidget> MisionRequestClass;

    

	UPROPERTY(EditAnywhere)
	float RestartDelay = 5.0f;

	UPROPERTY(EditAnywhere)
	UUserWidget* HUD;

	FTimerHandle RestartTimer;
};
