// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LBlackHole.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ALBlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALBlackHole();

	UPROPERTY(EditAnywhere)
	class USphereComponent* SphereComp;

	UPROPERTY(EditAnywhere)
	class URadialForceComponent* RadialForceComp;

	UPROPERTY(EditAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComp;

	UPROPERTY(EditAnywhere)
	class UParticleSystemComponent* BlackHoleParticleComp;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
					UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
					const FHitResult& SweepResult);
};
