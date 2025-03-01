// Fill out your copyright notice in the Description page of Project Settings.


#include "LAutoAttackActor.h"
#include "LMagicProjectile.h"
#include "Components/SphereComponent.h"

// Sets default values
ALAutoAttackActor::ALAutoAttackActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ALAutoAttackActor::BeginPlay()
{
	Super::BeginPlay();

	this->GetWorldTimerManager().SetTimer(ProjectileTimerHandle,this,&ALAutoAttackActor::TimeHandle_ProjectileTimerCallback,1.0f,true);
}

// Called every frame
void ALAutoAttackActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALAutoAttackActor::TimeHandle_ProjectileTimerCallback()
{
	FTransform SpawnTF = FTransform(this->GetActorRotation(),this->GetActorLocation());
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ALMagicProjectile* Projectile = Cast<ALMagicProjectile>(this->GetWorld()->SpawnActor<AActor>(ProjectileClass,SpawnTF,SpawnParams));
	Projectile->sphereComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECollisionResponse::ECR_Block);
}

