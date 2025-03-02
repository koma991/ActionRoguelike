// Fill out your copyright notice in the Description page of Project Settings.


#include "LProjectileDash.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ALProjectileDash::ALProjectileDash()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	DashSphere = CreateDefaultSubobject<USphereComponent>(TEXT("DashSphere"));
	DashSphere->SetupAttachment(RootComponent);
	DashSphere->SetSphereRadius(50.0f);

	DashParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("DashParticle"));
	DashParticle->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UParticleSystem> DashParticle_Template(TEXT("/Game/ParagonGideon/FX/Particles/Gideon/Abilities/Burden/FX/P_Gideon_Burden_Projectile.P_Gideon_Burden_Projectile"));
	if (DashParticle_Template.Succeeded())
	{
		DashParticle->SetTemplate(DashParticle_Template.Object);
	}

	DashProjectileSpeed = 1000.0f;
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = DashProjectileSpeed;
	ProjectileMovement->ProjectileGravityScale = 0.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;

	this->InitialLifeSpan = 1.5f;
}

// Called when the game starts or when spawned
void ALProjectileDash::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALProjectileDash::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

