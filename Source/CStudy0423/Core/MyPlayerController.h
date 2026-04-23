// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */


class UInputMappingContext;


UCLASS()
class CSTUDY0423_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;
public:
	AMyPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TArray<TSoftObjectPtr<UInputMappingContext>> InputMappingContext;

	
};
