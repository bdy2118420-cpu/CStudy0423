// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

AMyPlayerController::AMyPlayerController()
{

}

void AMyPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	if(IsLocalPlayerController())
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
		if(Subsystem)
		{
			Subsystem->ClearAllMappings();
			for(const auto& IMC : InputMappingContexts)
			{
				Subsystem->AddMappingContext(IMC.LoadSynchronous(), 0);
			}
		}
	}
}

void AMyPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
	if (IsLocalPlayerController())
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
		if (Subsystem)
		{
			Subsystem->ClearAllMappings();
		}
	}
}
