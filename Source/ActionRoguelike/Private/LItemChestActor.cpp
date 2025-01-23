// Fill out your copyright notice in the Description page of Project Settings.


#include "LItemChestActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
ALItemChestActor::ALItemChestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(BaseMesh);

	GoldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GoldMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualGoldMesh(TEXT("/Game/ExampleContent/Meshes/SM_Treasure_Pile.SM_Treasure_Pile"));
	if (VisualGoldMesh.Succeeded())
	{
		GoldMesh->SetStaticMesh(VisualGoldMesh.Object);
		GoldMesh->SetupAttachment(BaseMesh);
		GoldMesh->SetRelativeLocation(FVector(0, 0, 50.0f));
	}

	GoldParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("GoldParticle"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> VisualGoldParticle(TEXT("/Game/ExampleContent/Effects/P_Treasure_Burst.P_Treasure_Burst"));
	if (VisualGoldParticle.Succeeded())
	{
		GoldParticle->SetTemplate(VisualGoldParticle.Object);
		GoldParticle->SetupAttachment(GoldMesh);
		GoldParticle->bAutoActivate = false;
	}

	LidTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("LidTimeline"));
}

void ALItemChestActor::Interact_Implementation(APawn* InstigatorPawn)
{
	/*LidMesh->SetRelativeRotation(FRotator(TargetRot, 0.0f, 0.0f));*/

	
	if (LidTimeline->IsPlaying())
		LidTimeline->Reverse();
	else if (LidTimeline->IsReversing())
		LidTimeline->Play();
}

// Called when the game starts or when spawned
void ALItemChestActor::BeginPlay()
{
	Super::BeginPlay();

	if (CurveFloat)
	{
		OnTimelineFloat.BindDynamic(this,&ALItemChestActor::OpenLidCallback);
		OnTimelineEventFinish.BindUFunction(this,FName("FinishLidCallback"));
		LidTimeline->AddInterpFloat(CurveFloat,OnTimelineFloat);
		LidTimeline->SetTimelineFinishedFunc(OnTimelineEventFinish);
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

void ALItemChestActor::FinishLidCallback()
{
	GoldParticle->Activate();
}



