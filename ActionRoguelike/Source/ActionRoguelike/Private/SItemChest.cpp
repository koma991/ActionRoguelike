// Fill out your copyright notice in the Description page of Project Settings.


#include "SItemChest.h"
#include "Components/StaticMeshComponent.h"
#include "SCharacter.h"


// Sets default values
ASItemChest::ASItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComp");
	RootComponent = BaseMeshComp;

	LidMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("LidMeshComp");
	LidMeshComp->SetupAttachment(BaseMeshComp);


	TargetPitch = 110;
}

// Called when the game starts or when spawned
void ASItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/// <summary>
/// 设置Actor相对旋转
/// </summary>
/// <param name="pawn"></param>
void ASItemChest::Interface_Implementation(APawn* pawn)
{
	LidMeshComp->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
}

