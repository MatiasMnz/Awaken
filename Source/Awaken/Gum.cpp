// Fill out your copyright notice in the Description page of Project Settings.


#include "Gum.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Engine/DamageEvents.h"


// Sets default values
AGum::AGum()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AGum::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AGum::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGum::PullTrigger()
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr)
	{
		return;
	}
	AController* OwnerController = OwnerPawn->GetController();
	if (OwnerController == nullptr)
	{
		return;
	}
	FVector Location;
	FRotator Rotation;
    OwnerController->GetPlayerViewPoint(Location,Rotation);
	FVector End = Location + Rotation.Vector() * MaxRange;
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	bool bSuccess = GetWorld()->LineTraceSingleByChannel(HitResult, Location, End,ECollisionChannel::ECC_GameTraceChannel1, Params);
	if (bSuccess)
	{
	FVector ShotDirection = -Rotation.Vector();
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));
	//DrawDebugPoint(GetWorld(),HitResult.Location,20,FColor::Red,true);
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactFlash,HitResult.Location, ShotDirection.Rotation());
	UGameplayStatics::PlaySoundAtLocation(GetWorld(),MuzzleSoundImpact,HitResult.Location);
	AActor* HitActor = HitResult.GetActor();
	if (HitActor != nullptr)
	{
		FPointDamageEvent DamageEvent (Damage, HitResult, ShotDirection, nullptr);
        HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
	}
	}
}

