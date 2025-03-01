#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LMagicProjectile.generated.h"


class UProjectileMovementComponent;
class UParticleSystem;
class UParticleSystemComponent;
class USphereComponent;

UCLASS()
class ACTIONROGUELIKE_API ALMagicProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALMagicProjectile();

	UPROPERTY(EditAnywhere)
	USphereComponent* sphereComp;

	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* moveComp;

	UPROPERTY(EditAnywhere)
	UParticleSystemComponent* effectComp;

	UPROPERTY(EditAnywhere)
	UParticleSystem* effectSys;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnHit(
			UPrimitiveComponent* HitComponent,        
			AActor* OtherActor,                       
			UPrimitiveComponent* OtherComp,           
			FVector NormalImpulse,                    
			const FHitResult& Hit
		);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
