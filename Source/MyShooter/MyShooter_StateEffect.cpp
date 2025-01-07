// Fill out your copyright notice in the Description page of Project Settings.


#include "MyShooter_StateEffect.h"

bool UMyShooter_StateEffect::InitObject(/*APawn* Pawn*/)
{
	UE_LOG(LogTemp, Warning, TEXT("UMyShooter_StateEffect::InitObject"));
	return true;
	
}

void UMyShooter_StateEffect::ExecuteEffect(float DeltaTime)
{
}

void UMyShooter_StateEffect::DestroyObject()
{
}

bool UMyShooter_StateEffect::CheckStakableEffect()
{
	return true;
}
 