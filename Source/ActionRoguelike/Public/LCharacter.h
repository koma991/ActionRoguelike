// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Actor.h>

#include "CoreMinimal.h"
#include "LBlackHole.h"
#include "GameFramework/Character.h"
#include "LCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class ULInteractionComponent;
class UAnimMontage;

UCLASS()
class ACTIONROGUELIKE_API ALCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	ALCharacter();

	UPROPERTY(EditAnywhere)
	float AttackTimer;
	UPROPERTY(EditAnywhere)
	float BlockHoleTimer;
	UPROPERTY(EditAnywhere)
	float BlockHoleTimeCount;
	UPROPERTY(EditAnywhere)
	float AttackTimeCount;
	UPROPERTY(EditAnywhere)
	bool bIsBlockHole;
	UPROPERTY(EditAnywhere)
	bool bIsAttack;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(VisibleAnywhere)
	ULInteractionComponent* InteractionComp;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> BlackHoleClass;

	UPROPERTY(EditAnywhere,Category="Attack")
	UAnimMontage* PrimaryInteractMontage;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> Crosshair_Widget;
	
	UUserWidget* CrossWidget;

	FTimerHandle TimeHandle_PrimaryInteract;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float value);
	void MoveRight(float value);
	void PrimaryAttack();
	void PrimaryInteract();
	void PrimaryBlackHole();
	
	void PrimaryInteract_TimeExpose();
	void Timer(float DeltaTime);
};
