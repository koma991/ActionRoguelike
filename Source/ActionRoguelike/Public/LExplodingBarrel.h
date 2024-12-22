// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LExplodingBarrel.generated.h"

class UStaticMeshComponent;
class UParticleSystem;
class URadialForceComponent;

UCLASS()
class ACTIONROGUELIKE_API ALExplodingBarrel : public AActor
{
	GENERATED_BODY()
	
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
			UPrimitiveComponent* HitComponent,        // 碰撞发生的组件
			AActor* OtherActor,                       // 发生碰撞的另一个 Actor
			UPrimitiveComponent* OtherComp,           // 另一个组件
			FVector NormalImpulse,                    // 法线方向上的冲击力
			const FHitResult& Hit
		);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
