

#include "PresentPawn.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APresentPawn::APresentPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void APresentPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APresentPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector EnemyMov = FVector(0, -2, 0);
	SetActorLocation(GetActorLocation() + EnemyMov);
}

// Called to bind functionality to input
void APresentPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
