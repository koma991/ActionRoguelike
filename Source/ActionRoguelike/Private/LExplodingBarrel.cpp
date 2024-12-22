// Fill out your copyright notice in the Description page of Project Settings.


#include "LExplodingBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "Particles//ParticleSystem.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ALExplodingBarrel::ALExplodingBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	RootComponent = meshComp;
	meshComp->SetSimulatePhysics(true);

	radiaForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("radiaForceComp"));
	radiaForceComp->SetupAttachment(meshComp);
	radiaForceComp->Radius = 600.0f;
	radiaForceComp->ImpulseStrength = 1000.0f;
	radiaForceComp->bImpulseVelChange = true;
	radiaForceComp->AddCollisionChannelToAffect(ECC_WorldDynamic);

	explodingEffect = CreateDefaultSubobject<UParticleSystem>(TEXT("explodingEffect"));

}

// Called when the game starts or when spawned
void ALExplodingBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}


void ALExplodingBarrel::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	meshComp->OnComponentHit.AddDynamic(this, &ALExplodingBarrel::OnHit);
}

void ALExplodingBarrel::OnHit(UPrimitiveComponent* HitComponent, /* 碰撞发生的组件 */ AActor* OtherActor, /* 发生碰撞的另一个 Actor */ UPrimitiveComponent* OtherComp, /* 另一个组件 */ FVector NormalImpulse, /* 法线方向上的冲击力 */ const FHitResult& Hit)
{
	FTransform spawnTF = FTransform(FRotator::ZeroRotator, Hit.ImpactPoint);
	UGameplayStatics::SpawnEmitterAtLocation(this->GetWorld(), explodingEffect, spawnTF);
	radiaForceComp->FireImpulse();
}

// Called every frame
void ALExplodingBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

