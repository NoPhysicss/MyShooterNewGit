// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyShooter/FuncLibrary/LibTypes.h"
#include "TimerManager.h"
#include "MyShooter/WeaponDefault.h"
#include "MyShooter/MyShooterInstance.h"
#include "MyShooter/Cherecter/MyInventoryComponent.h"
#include "MyShooter/Cherecter/MyShooterCharHealthComponent.h"
#include "MyShooter/Cherecter/MyShooterHealthComponent.h"
#include "MyShooter/Game/MyShooterPlayerController.h"
#include "MyShooter/MyShooter_StateEffect.h"
#include "MyShooter/Interface/MyShooter_IGameActor.h"
#include "MyShooterCharacter.generated.h"


UCLASS(Blueprintable)
class AMyShooterCharacter : public ACharacter, public IMyShooter_IGameActor
{
	GENERATED_BODY()

public:
	AMyShooterCharacter();

	FTimerHandle TimerHandle_RagDollTimer;

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputMoveComponent) override;

	virtual void BeginPlay() override;


	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UMyInventoryComponent* InventoryComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UMyShooterCharHealthComponent* CharHealthComponent;

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

public:

	//Cursor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface* CursorMaterial = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursoreSize = FVector(20.f, 40.f, 40.f);

	UFUNCTION(BlueprintCallable)
	UDecalComponent* GetCursorToWorld();

	UDecalComponent* CurrentCursor = nullptr;

	//Movement 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	EMovementState MovementState = EMovementState::Normal_State;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FCharacterSpeed MovementInfo;



	//movement mod
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool RunEnable = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool WalkEnable = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool AimEnable = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool NormalWalkEnable = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool bIsAlive = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	TArray<UAnimMontage*> DeadsAnim;

	//weapon
	AWeaponDefault* CurrentWeapon = nullptr;

	//for demo 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Demo")
	FName InitWeaponName;

	UFUNCTION()
	void InputAttackPressed();
	UFUNCTION()
	void InputAttackReleased();

	UFUNCTION(BlueprintCallable)
	void AttackCharEvent(bool bIsFiring);

	UFUNCTION(BlueprintCallable)
	AWeaponDefault* GetCurrentWeapon();
	UFUNCTION(BlueprintCallable)
	void InitWeapon(FName IdWeaponName, FAdditionalWeaponInfo WeaponAdditionalInfo, int32 NewCurrentIndexWeapon);
	UFUNCTION(BlueprintCallable)//VisualOnly
		void RemoveCurrentWeapon();
	UFUNCTION(BlueprintCallable)
	void TryReloadWeapon();
	UFUNCTION(BlueprintCallable)
	void WeaponReloadStart(UAnimMontage* Anim);
	UFUNCTION()
	void WeaponReloadEnd(bool bIsSuccess, int32 AmmoSafe);
	UFUNCTION(BlueprintNativeEvent)
	void WeaponReloadStart_BP(UAnimMontage* Anim);
	UFUNCTION(BlueprintNativeEvent)
	void WeaponReloadEnd_BP(bool bIsSuccess);

	UFUNCTION()
	void WeaponFireStart(UAnimMontage* Anim);
	UFUNCTION(BlueprintNativeEvent)
	void WeaponFireStart_BP(UAnimMontage* Anim);

	bool bisReloding = false;

	UFUNCTION()
	void MoveInputAxisY(float Value);
	UFUNCTION()
	void MoveInputAxisX(float Value);

	float AxisX = 0.0f;
	float AxisY = 0.0f;

	UFUNCTION()
	void MovementTick(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void CharacterUpdate();
	UFUNCTION(BlueprintCallable)
	void ChangeMovementState();

	UFUNCTION(BlueprintCallable)
	void RunMovementState();

	FVector LookDirection;
	FVector MoveDirection;
	float SpeedModif = 1.0f;

	//Boom camera wheelth
	UFUNCTION(BlueprintCallable)
	void BCameraInputAxis(float Value);

	float CameraAxis = 0.0f;

	UFUNCTION(BlueprintCallable)
	void BoomCameraWeight();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float CameraWeightChange = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float CameraMaxWeight = 3000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float CameraMinWeight = 200.0f;

	bool bIsBloom;

	void TrySwicthNextWeapon();
	void TrySwitchPreviosWeapon();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	int32 CurrentIndexWeapon = 0;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	
	
	UFUNCTION()
	void CharDead();
	
	void EnableRagDoll();


	//Interface
	//bool AviableForEffects_Implementation() override;
	EPhysicalSurface GetSurfaceType() override;
};

