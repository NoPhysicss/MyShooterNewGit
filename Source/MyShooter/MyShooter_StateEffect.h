// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "MyShooter_StateEffect.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MYSHOOTER_API UMyShooter_StateEffect : public UObject
{
	GENERATED_BODY()

public:

	virtual bool InitObject(/*APawn* Pawn*/);
	virtual void ExecuteEffect(float DeltaTime);
	virtual void DestroyObject();

	virtual bool CheckStakableEffect();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setting")
	TArray<TEnumAsByte<EPhysicalSurface>> PossibleInteractSurface;





};
