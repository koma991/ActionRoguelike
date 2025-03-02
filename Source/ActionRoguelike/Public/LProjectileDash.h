// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LProjectileDash.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ALProjectileDash : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALProjectileDash();

	UPROPERTY(VisibleAnywhere)
	class UParticleSystemComponent* DashParticle;
	
	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* DashSphere;


	UPROPERTY(EditAnywhere)
	float DashProjectileSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,FVector NormalImpulse, const FHitResult& Hit);
};

