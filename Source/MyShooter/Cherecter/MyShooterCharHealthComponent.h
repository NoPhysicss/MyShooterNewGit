// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyShooter/Cherecter/MyShooterHealthComponent.h"
#include "MyShooterCharHealthComponent.generated.h"

/**
 * 
 */
UCLASS()
class MYSHOOTER_API UMyShooterCharHealthComponent : public UMyShooterHealthComponent
{
	GENERATED_BODY()
	
public:

	
	void ChangeCurrentHealt(float ChangeValue) override;
};
