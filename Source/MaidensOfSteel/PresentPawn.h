

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PresentPawn.generated.h"

UCLASS()
class MAIDENSOFSTEEL_API APresentPawn : public APawn
{
	GENERATED_BODY()

	

public:
	// Sets default values for this pawn's properties
	APresentPawn();
	
	UPROPERTY(Category = MeshComponent, VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* MeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
