// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"


//前置声明
class USpringArmComponent;
class UCameraComponent;
class USInteractorComponent;
class UAnimMontage;

UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()


protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileClass;


//函数
public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveRight(float value);

	void PrimaryAttack();
	void PrimaryInteract();

	void PlayAttackAnim();

//属性
protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;
	UPROPERTY(VisibleAnywhere)
	USInteractorComponent* InsteractComp;

	UPROPERTY(EditAnywhere)
	float DrawScale;
	UPROPERTY(EditAnywhere)
	float Thickness;

	UPROPERTY(EditDefaultsOnly,Category = "Anim")
	UAnimMontage* AttackAnim;

	//移动
	UPROPERTY(EditAnywhere);
	float MoveSpeed;

	FTimerHandle TimeHandle;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
