// Fill out your copyright notice in the Description page of Project Settings.


#include "LItemChestActor.h"

#include <string>

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

	OpenTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("OpenTimeline"));

	static ConstructorHelpers::FObjectFinder<UCurveFloat> VisualLidCanvas(TEXT("/Game/ActionRoguelike/BP/LidCurve.LidCurve"));
	if (VisualLidCanvas.Succeeded())
	{
		OpenCurve = VisualLidCanvas.Object;
	}
}

void ALItemChestActor::Interact_Implementation(APawn* InstigatorPawn)
{
	/*LidMesh->SetRelativeRotation(FRotator(TargetRot, 0.0f, 0.0f));*/

	if (OpenTimeline && !OpenTimeline->IsPlaying())
	{
		OpenTimeline->Play();
	}
}

// Called when the game starts or when spawned
void ALItemChestActor::BeginPlay()
{
	Super::BeginPlay();

	
	if (OpenCurve)
	{
		/*UpdateTimelineLidDelegate.BindUFunction(this,FName("UpdateTimelineLidFloat"));
		FinishTimelineLidDelegate.BindUFunction(this,FName("FinishTimelineLidFloat"));*/
		UpdateTimelineLidDelegate.BindDynamic(this,&ALItemChestActor::UpdateLidRotation);
		FinishTimelineLidDelegate.BindDynamic(this,&ALItemChestActor::FinishLidRotation);

		OpenTimeline->AddInterpFloat(OpenCurve,UpdateTimelineLidDelegate);
		OpenTimeline->SetTimelineFinishedFunc(FinishTimelineLidDelegate);
	}
}

// Called every frame
void ALItemChestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALItemChestActor::UpdateLidRotation(float value)
{
	const float StartPitch = LidMesh->GetRelativeRotation().Pitch;
	const float EndPitch = 90.0f;
	const float NewPitch = FMath::Lerp(StartPitch,EndPitch,value);
	GEngine->AddOnScreenDebugMessage(0,5.0f,FColor::Red,FString::Printf(TEXT("%f"),NewPitch));
	LidMesh->SetRelativeRotation(FRotator(NewPitch,0.0f,0.0f));
}

void ALItemChestActor::FinishLidRotation()
{
	
}



