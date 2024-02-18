// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SLevel.generated.h"


class AExplosiveBarrel;
class UStaticMeshComponent;


UCLASS()
class ACTIONROGUELIKE_API ASLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(EditAnywhere)
	AExplosiveBarrel* Barrel;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* HandMesh;
	UPROPERTY(VisibleAnywhere)
	bool bHasDown;



public:
	UFUNCTION()
	void Explode();

};
