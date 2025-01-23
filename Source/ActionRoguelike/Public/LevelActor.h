// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LExplodingBarrel.h"
#include "LGameplayInterface.h"
#include "LItemChestActor.h"
#include "GameFramework/Actor.h"
#include "LevelActor.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ALevelActor : public AActor, public ILGameplayInterface
{
	GENERATED_BODY()

	void Interact_Implementation(APawn* InstigatorPawn);
public:	
	// Sets default values for this actor's properties
	ALevelActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* HandleMesh;

	UPROPERTY(EditAnywhere)
	ALItemChestActor* ChestActor;
	UPROPERTY(EditAnywhere)
	ALExplodingBarrel* ExplodingBarrel;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
