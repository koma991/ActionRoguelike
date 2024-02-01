// Fill out your copyright notice in the Description page of Project Settings.


#include "SMagicProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ASMagicProjectile::ASMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	//将SphereComp设置为根组件
	RootComponent = SphereComp;
	SphereComp->SetCollisionProfileName("Projectile");

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);

	ProjectileMoveComp = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMoveComp");
	ProjectileMoveComp->InitialSpeed = 1500.0f;
	//让Actor的方向自动朝向我需要飞的方向，不需要手动设置旋转
	ProjectileMoveComp->bRotationFollowsVelocity = true;
	//让Actor以自身的方向为基准
	ProjectileMoveComp->bInitialVelocityInLocalSpace = true;
	ProjectileMoveComp->ProjectileGravityScale = 0.0f;
}

// Called when the game starts or when spawned
void ASMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

