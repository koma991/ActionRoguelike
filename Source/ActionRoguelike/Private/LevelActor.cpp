// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelActor.h"

#include "Components/ArrowComponent.h"


// Sets default values
ALevelActor::ALevelActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualBaseMesh(TEXT("/Game/ExampleContent/Meshes/SM_Interactive_Switch.SM_Interactive_Switch"));
	if (VisualBaseMesh.Succeeded())
	{
		BaseMesh->SetStaticMesh(VisualBaseMesh.Object);
		RootComponent = BaseMesh;
	}
	HandleMesh = CreateDefaultSubobject<UStaticMeshComponent>("HandleMesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualHandleMesh(TEXT("/Game/ExampleContent/Meshes/SM_Interactive_Switch_Handle.SM_Interactive_Switch_Handle"));
	if (VisualHandleMesh.Succeeded())
	{
		HandleMesh->SetStaticMesh(VisualHandleMesh.Object);
		HandleMesh->SetupAttachment(BaseMesh);
		HandleMesh->SetRelativeRotation(FRotator(30.0f,0, 0));
	}
	ChestActor = CreateDefaultSubobject<ALItemChestActor>("ChestActor");
	ExplodingBarrel = CreateDefaultSubobject<ALExplodingBarrel>(TEXT("ExplodingBarrel"));
}

// Called when the game starts or when spawned
void ALevelActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelActor::Interact_Implementation(APawn* InstigatorPawn)
{
	HandleMesh->SetRelativeRotation(FRotator(-30.0f,0, 0));
	ChestActor->Interact_Implementation(InstigatorPawn);
	ExplodingBarrel->Interact_Implementation(InstigatorPawn);
}