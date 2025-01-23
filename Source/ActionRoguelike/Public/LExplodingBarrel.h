// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "LExplodingBarrel.generated.h"

class UStaticMeshComponent;
class UParticleSystem;
class URadialForceComponent;

UCLASS()
class ACTIONROGUELIKE_API ALExplodingBarrel : public AActor,public ILGameplayInterface
{
	GENERATED_BODY()

public:
	void Interact_Implementation(APawn* InstigatorPawn);
	
public:	
	// Sets default values for this actor's properties
	ALExplodingBarrel();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* meshComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	URadialForceComponent* radiaForceComp;

	UPROPERTY(EditAnywhere)
	UParticleSystem* explodingEffect;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnHit(
			UPrimitiveComponent* HitComponent,        // ��ײ���������
			AActor* OtherActor,                       // ������ײ����һ�� Actor
			UPrimitiveComponent* OtherComp,           // ��һ�����
			FVector NormalImpulse,                    // ���߷����ϵĳ����
			const FHitResult& Hit
		);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
