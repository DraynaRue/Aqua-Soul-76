

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlayerInstance.generated.h"

/**
 * 
 */
UCLASS()
class MAIDENSOFSTEEL_API UPlayerInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Category = Gameplay, VisibleAnywhere, BlueprintReadWrite)
	float score;

	UPROPERTY(Category = Gameplay, VisibleAnywhere, BlueprintReadWrite)
	float currentTime;
	
};
