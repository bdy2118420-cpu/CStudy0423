// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"

void UMyAnimInstance::NativeInitializeAnimation()
{
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ACharacter* Player = Cast< ACharacter >(TryGetPawnOwner());
	if (Player)
	{
		Speed = Player->GetCharacterMovement()->Velocity.Size();
		Direction = UKismetAnimationLibrary::CalculateDirection(Player->GetVelocity(), Player->GetActorRotation());
	}
}

void UMyAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
}
