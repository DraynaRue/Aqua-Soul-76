// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpawner.h"
#include "Engine/World.h"
#include "PresentPawn.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* const World = GetWorld();
	if (bCanSpawn)
	{
		// spawn the enemy
		FActorSpawnParameters params;
		params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		params.bNoFail = true;
		params.Owner = GetOwner();
		params.Instigator = Cast<APawn>(GetOwner());

		float BadPresSpawnChance = FMath::RandRange(0, 10);
		if (BadPresSpawnChance >=7)
		{
			// Spawn Bad Present
			APresentPawn* spawnedactor = World->SpawnActor<APresentPawn>(BadType, SpawnPoint->GetActorLocation(), SpawnPoint->GetActorRotation(), params);
			if (spawnedactor != nullptr)
			{
			//	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, TEXT("Spawn!!"));
			}
		}
		else if (BadPresSpawnChance < 7)
		{
			// Spawn Good Present
			APresentPawn* spawnedactor = World->SpawnActor<APresentPawn>(PresentType, SpawnPoint->GetActorLocation(), SpawnPoint->GetActorRotation(), params);
			if (spawnedactor != nullptr)
			{
			//	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, TEXT("Spawn!!"));
			}
		}
		
		bCanSpawn = false;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle_SpawnTimerExpired, this, &AEnemySpawner::SpawnTimerExpired, SpawnRate);
	}
}

void AEnemySpawner::SpawnTimerExpired()
{
	bCanSpawn = true;
}

