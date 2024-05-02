// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
    Super::BeginPlay();
    UWorld* World = GetWorld();
    FTimerHandle TimerHandle;
    float WidgetDuration = 5.0f;
    MisionRequest = CreateWidget(this, MisionRequestClass);
    if (MisionRequest != nullptr)
        {
        MisionRequest->AddToViewport();
        World->GetTimerManager().SetTimer(TimerHandle,this,&AShooterPlayerController::RemoveWidget,WidgetDuration,false);
    }

    HUD = CreateWidget(this, HUDClass);
    if (HUD != nullptr)
    {
        HUD->AddToViewport();
    }
}

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    HUD->RemoveFromParent();
    if (bIsWinner)
    {
        UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
        if (WinScreen != nullptr)
        {
        WinScreen->AddToViewport();
        }
    }
    else
    {
        UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
        if (LoseScreen != nullptr)
        {
        LoseScreen->AddToViewport();
        }
    }
    

    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

void AShooterPlayerController::RemoveWidget()
{
    if (MisionRequest != nullptr)
    {
        MisionRequest->RemoveFromParent();
    }
    
    
}


