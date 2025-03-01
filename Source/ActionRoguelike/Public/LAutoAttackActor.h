// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LAutoAttackActor.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ALAutoAttackActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALAutoAttackActor();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> ProjectileClass;

	FTimerHandle ProjectileTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void TimeHandle_ProjectileTimerCallback();
};
