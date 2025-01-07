// Fill out your copyright notice in the Description page of Project Settings.


#include "MyShooter/Cherecter/MyShooterCharHealthComponent.h"

void UMyShooterCharHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle_CoolDownShieldTimer, this, &UMyShooterCharHealthComponent::CoolDownShieldEnd, CoolDownShieldRecover, false);
}


void UMyShooterCharHealthComponent::ChangeCurrentHealt(float ChangeValue)
{


	float CurrentDamage = ChangeValue;

	if (Shield > 0.0f && ChangeValue < 0.0f)
	{
		if (Shield < (ChangeValue * -1))
		{
			CurrentDamage = ChangeValue + Shield;
			ChangeCurrentShield(ChangeValue);
			Super::ChangeCurrentHealt(CurrentDamage);	
		}
		else
		{
			ChangeCurrentShield(ChangeValue);
		}
	}
	else
	{
		Super::ChangeCurrentHealt(CurrentDamage);
	}
}






void UMyShooterCharHealthComponent::ChangeCurrentShield(float ChangeValue)
{
	
	Shield += ChangeValue;
	
	if (Shield > MaxShield)
	{
		Shield = MaxShield;
	}
	else if (Shield < 0.0f)
	{
			Shield = 0.0f;
	}

	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle_CoolDownShieldTimer, this, &UMyShooterCharHealthComponent::CoolDownShieldEnd, CoolDownShieldRecover, false);
	
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle_ShieldRecoverRateTimer);
	}
	OnShieldChange.Broadcast(Shield, ChangeValue);
}

void UMyShooterCharHealthComponent::CoolDownShieldEnd()
{
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandle_ShieldRecoverRateTimer, this, &UMyShooterCharHealthComponent::RecoveryShield, ShieldRecoverRate, true);
	}
}

float UMyShooterCharHealthComponent::GetCurrentShield()
{
	return Shield;
}

void UMyShooterCharHealthComponent::RecoveryShield()
{
	Shield += ShieldRecoverValue;
	if (Shield > MaxShield)
	{
		Shield = MaxShield;
		
			if (GetWorld())
			{
				GetWorld()->GetTimerManager().ClearTimer(TimerHandle_ShieldRecoverRateTimer);
			}
	}
	OnShieldChange.Broadcast(Shield, ShieldRecoverValue);
}

float UMyShooterCharHealthComponent::GetMaxShield()
{
	return MaxShield;
}

