// Fill out your copyright notice in the Description page of Project Settings.


#include "LBlackHole.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ALBlackHole::ALBlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCompo"));
	SphereComp->SetupAttachment(RootComponent);
	SphereComp->SetSphereRadius(80.0f);
	SphereComp->SetSimulatePhysics(false);
	SphereComp->SetGenerateOverlapEvents(true);
	
	BlackHoleParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BlackHoleParticleComp"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/ParagonGideon/FX/Particles/Gideon/Abilities/Ultimate/FX/P_Gideon_Ultimate.P_Gideon_Ultimate"));
	if (ParticleAsset.Succeeded())
	{
		BlackHoleParticleComp->SetTemplate(ParticleAsset.Object);
		BlackHoleParticleComp->Activate(true);
	}
	BlackHoleParticleComp->SetupAttachment(RootComponent);

	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForceComponent"));
	RadialForceComp->SetupAttachment(RootComponent);
	RadialForceComp->Radius = 1000.0f;
	RadialForceComp->ForceStrength = -1500000.0f;
	RadialForceComp->Falloff = ERadialImpulseFalloff::RIF_Linear;
	RadialForceComp->RemoveObjectTypeToAffect(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	this->InitialLifeSpan = 4.8f;

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	ProjectileMovementComp->InitialSpeed = 1000.0f;
	ProjectileMovementComp->ProjectileGravityScale = 0.0f;
	ProjectileMovementComp->bRotationFollowsVelocity = true;


	SphereComp->OnComponentBeginOverlap.AddDynamic(this,&ALBlackHole::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ALBlackHole::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RadialForceComp->FireImpulse();
}

void ALBlackHole::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp->IsSimulatingPhysics())
	{
		OtherActor->Destroy(true);
	}
}

