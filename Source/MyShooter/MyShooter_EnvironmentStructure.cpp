// Fill out your copyright notice in the Description page of Project Settings.


#include "MyShooter_EnvironmentStructure.h"

// Sets default values
AMyShooter_EnvironmentStructure::AMyShooter_EnvironmentStructure()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyShooter_EnvironmentStructure::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyShooter_EnvironmentStructure::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

EPhysicalSurface AMyShooter_EnvironmentStructure::GetSurfaceType()
{
	EPhysicalSurface Result = EPhysicalSurface::SurfaceType_Default;
	UStaticMeshComponent* myMesh = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
	if (myMesh)
	{
		UMaterialInterface* myMaterial = myMesh->GetMaterial(0);
		if (myMaterial)
		{
			Result = myMaterial->GetPhysicalMaterial()->SurfaceType;
		}
	}
	return Result;
}

/*bool AMyShooter_EnvironmentStructure::AviableForEffectsOnlyCPP()
{
	UE_LOG(LogTemp, Warning, TEXT("AMyShooter_EnvironmentStructure::AviableForEffects_OnlyCPP "))
	return true;
}

bool AMyShooter_EnvironmentStructure::AviableForEffects_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("AMyShooter_EnvironmentStructure::AviableForEffects_Implementation "))
	return false;
}*/


