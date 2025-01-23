// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LGameplayInterface.h"
#include "Components/TimelineComponent.h"
#include "LItemChestActor.generated.h"


class FOnTimelineFloat;
class UStaticMeshComponent;
class UTimelineComponent;
class UParticleSystemComponent;

UCLASS()
class ACTIONROGUELIKE_API ALItemChestActor : public AActor, public ILGameplayInterface
{
	GENERATED_BODY()
	
public:
	void Interact_Implementation(APawn* InstigatorPawn);
	
public:	
	// Sets default values for this actor's properties
	ALItemChestActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* LidMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* GoldMesh;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* GoldParticle;
	
	UPROPERTY(VisibleAnywhere)
	UTimelineComponent* LidTimeline;

	UPROPERTY(EditAnywhere)
	UCurveFloat* CurveFloat;

	FOnTimelineFloat OnTimelineFloat;
	FOnTimelineEvent OnTimelineEventFinish;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()
	void OpenLidCallback(float Value);
	
	UFUNCTION()
	void FinishLidCallback();
};
