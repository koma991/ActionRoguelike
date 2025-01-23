// Fill out your copyright notice in the Description page of Project Settings.


#include "LItemChestActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"


// Sets default values
ALItemChestActor::ALItemChestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(BaseMesh);

	LidTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("LidTimeline"));
}

void ALItemChestActor::Interact_Implementation(APawn* InstigatorPawn)
{
	/*LidMesh->SetRelativeRotation(FRotator(TargetRot, 0.0f, 0.0f));*/

	LidTimeline->Play();
}

// Called when the game starts or when spawned
void ALItemChestActor::BeginPlay()
{
	Super::BeginPlay();

	if (CurveFloat)
	{
		OnTimelineFloat.BindDynamic(this,&ALItemChestActor::OpenLidCallback);
		LidTimeline->AddInterpFloat(CurveFloat,OnTimelineFloat);
		LidTimeline->SetLooping(false);
	}
}

// Called every frame
void ALItemChestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALItemChestActor::OpenLidCallback(float Value)
{
	FRotator NewRotation = FRotator(Value,0, 0);
	LidMesh->SetRelativeRotation(NewRotation);
}



