// Fill out your copyright notice in the Description page of Project Settings.


#include "LItemChestActor.h"
#include "Components/StaticMeshComponent.h"
#include "LGameplayInterface.h"


// Sets default values
ALItemChestActor::ALItemChestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(BaseMesh);

	targetRot = 110.0f;
}

void ALItemChestActor::Interact_Implementation(APawn* InstigatorPawn)
{
	LidMesh->SetRelativeRotation(FRotator(targetRot, 0.0f, 0.0f));
}

// Called when the game starts or when spawned
void ALItemChestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALItemChestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


