// Fill out your copyright notice in the Description page of Project Settings.

#include "LibTypes.h"
#include "MyShooter/MyShooter.h"

void ULibTypes::AddEffectBySurfaceType(AActor* TakeEffectActor,TSubclassOf<UMyShooter_StateEffect> AddEffectClass, EPhysicalSurface SurfaceType)
{
	if (SurfaceType != EPhysicalSurface::SurfaceType_Default && TakeEffectActor && AddEffectClass)
	{
		UMyShooter_StateEffect* myEffect = Cast<UMyShooter_StateEffect>(AddEffectClass->GetDefaultObject());
		if (myEffect)
		{
			bool bIsCanAdd = false;
			int8 i = 0;
			while (i < myEffect->PossibleInteractSurface.Num() && !bIsCanAdd)
			{
				if (myEffect->PossibleInteractSurface[i] == SurfaceType)
				{
					bIsCanAdd = true;
					UMyShooter_StateEffect* NewEffect = NewObject<UMyShooter_StateEffect>(TakeEffectActor, FName("Effect"));
					if (NewEffect)
					{
						NewEffect->InitObject();
					}
				}
				i++;
			}
		}
		
	}
}
 