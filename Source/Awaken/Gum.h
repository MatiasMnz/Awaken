// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gum.generated.h"

UCLASS()
class AWAKEN_API AGum : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGum();
	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

    UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

    UPROPERTY(EditAnywhere)
	USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere)
	USoundBase* MuzzleSoundImpact;

	UPROPERTY(EditAnyWhere)
	UParticleSystem* ImpactFlash;

	UPROPERTY(EditAnywhere)
	float MaxRange = 1000;
	
	UPROPERTY(EditAnywhere)
	float Damage = 30;

};
