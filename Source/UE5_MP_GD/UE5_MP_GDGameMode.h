// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UE5_MP_GDGameMode.generated.h"

UCLASS(minimalapi)
class AUE5_MP_GDGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUE5_MP_GDGameMode();

	UFUNCTION(BlueprintCallable)
	void HostLANGame();

	UFUNCTION(BlueprintCallable)
	void JoinLANGame();
	
};



