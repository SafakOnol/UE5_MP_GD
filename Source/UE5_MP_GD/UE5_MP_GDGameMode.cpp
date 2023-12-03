// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5_MP_GDGameMode.h"
#include "UE5_MP_GDCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5_MP_GDGameMode::AUE5_MP_GDGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AUE5_MP_GDGameMode::HostLANGame()
{
	GetWorld()->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen"); // adding ?Listen to the and defines this as a listen server
}

void AUE5_MP_GDGameMode::JoinLANGame()
{
	if(APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController())
	{
		PlayerController->ClientTravel("192.168.2.11", TRAVEL_Absolute); // Connect to Local LAN Address of the Listen Server (in this case it's my computer)
	}
}
