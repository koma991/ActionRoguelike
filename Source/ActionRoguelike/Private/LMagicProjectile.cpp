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


	sphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("sphereComp"));
	sphereComp->SetupAttachment(RootComponent);
	sphereComp->SetCollisionObjectType(ECC_WorldDynamic);
	sphereComp->SetCollisionProfileName("Projectile");

	effectComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("effectComp"));
	effectComp->SetupAttachment(sphereComp);
	
	moveComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("moveComp"));
	moveComp->InitialSpeed = 1000.0f;
	moveComp->bRotationFollowsVelocity = true;
	moveComp->bInitialVelocityInLocalSpace = true;
	moveComp->ProjectileGravityScale = 0.0f;


	//¶¯Ì¬°ó¶¨sphereCompÅö×²º¯Êý
	sphereComp->OnComponentBeginOverlap.AddDynamic(this, &ALMagicProjectile::OnComponentBeginOverlap);
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

void ALMagicProjectile::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FVector impactPoint = SweepResult.ImpactPoint;
	UGameplayStatics::SpawnEmitterAtLocation(this->GetWorld(), effectSys, impactPoint, FRotator::ZeroRotator, true, EPSCPoolMethod::None, true);
}

