// Fill out your copyright notice in the Description page of Project Settings.


#include "LMagicProjectile.h"

#include "LAutoAttackActor.h"
#include "LCharacter.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ALMagicProjectile::ALMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	sphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("sphereComp"));
	sphereComp->SetupAttachment(RootComponent);
	sphereComp->SetNotifyRigidBodyCollision(true);
	sphereComp->SetGenerateOverlapEvents(false);
	sphereComp->SetCollisionObjectType(ECC_WorldDynamic);
	sphereComp->SetCollisionProfileName("Projectile");

	effectComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("effectComp"));
	effectComp->SetupAttachment(sphereComp);
	
	moveComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("moveComp"));
	moveComp->InitialSpeed = 1000.0f;
	moveComp->bRotationFollowsVelocity = true;
	moveComp->bInitialVelocityInLocalSpace = true;
	moveComp->ProjectileGravityScale = 0.0f;
	
}

// Called when the game starts or when spawned
void ALMagicProjectile::BeginPlay()
{
	Super::BeginPlay();

	//sphereComp->OnComponentHit.AddDynamic(this, &ALMagicProjectile::OnComponentHit);
}

void ALMagicProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	sphereComp->OnComponentHit.AddDynamic(this, &ALMagicProjectile::OnHit);
}

// Called every frame
void ALMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALMagicProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	FVector ImpactPoint = Hit.ImpactPoint;
	UGameplayStatics::SpawnEmitterAtLocation(this->GetWorld(), effectSys, ImpactPoint, FRotator::ZeroRotator, true, EPSCPoolMethod::None, true);
	this->Destroy();
}

