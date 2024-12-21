// Fill out your copyright notice in the Description page of Project Settings.


#include "LMagicProjectile.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ALMagicProjectile::ALMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	sphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	sphereComp->SetupAttachment(RootComponent);
	sphereComp->SetCollisionObjectType(ECC_WorldDynamic);
	sphereComp->SetCollisionProfileName("Projectile");

	effectComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EffectComp"));
	effectComp->SetupAttachment(sphereComp);
	
	moveComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MoveComp"));
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

// Called every frame
void ALMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ALMagicProjectile::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
//{
//	UGameplayStatics::SpawnEmitterAtLocation(this->GetWorld(), effectSys, Hit.ImpactPoint, FRotator::ZeroRotator);
//}

