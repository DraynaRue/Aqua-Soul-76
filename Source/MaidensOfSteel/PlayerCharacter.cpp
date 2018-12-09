// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/World.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "TriggerComponent.h"
#include "PlayerInstance.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerComponent = CreateDefaultSubobject<UTriggerComponent>(TEXT("TriggerCompenent"));
	TriggerComponent->FireRate = FireRate;

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (doTimerStart == true)
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle_GameTimer, this, &APlayerCharacter::GameTimerExpired, 120.0f);
	}
}

void APlayerCharacter::GameTimerExpired()
{
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UPlayerInstance* pInst = Cast<UPlayerInstance>(GetGameInstance());
	pInst->currentTime = GetWorld()->GetTimerManager().GetTimerRemaining(TimerHandle_GameTimer);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	// set up action bindings

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::FireShotPress);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &APlayerCharacter::FireShotRelease);
	
	// set up axis bindings
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

}

void APlayerCharacter::FireShotPress()
{
	TriggerComponent->doFire = true;
}

void APlayerCharacter::FireShotRelease()
{
	TriggerComponent->doFire = false;
}

void APlayerCharacter::ShotTimerExpired()
{
	bCanFire = true;
}

void APlayerCharacter::MoveRight(float RightValue)
{
	if (RightValue != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), RightValue);
	}
}