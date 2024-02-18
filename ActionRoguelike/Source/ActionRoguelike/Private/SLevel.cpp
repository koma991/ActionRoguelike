// Fill out your copyright notice in the Description page of Project Settings.


#include "SLevel.h"
#include "ExplosiveBarrel.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASLevel::ASLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;
	HandMesh = CreateDefaultSubobject<UStaticMeshComponent>("HandMesh");
	HandMesh->SetupAttachment(BaseMesh);
	Barrel = CreateDefaultSubobject<AExplosiveBarrel>("Barrel");
	bHasDown = false;

}

// Called when the game starts or when spawned
void ASLevel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASLevel::Explode()
{
	if (!bHasDown && Barrel) {
		bHasDown = true;
		Barrel->Dynamic();
	}
}

