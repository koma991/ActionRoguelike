// Fill out your copyright notice in the Description page of Project Settings.


#include "LInteractionComponent.h"

#include "DrawDebugHelpers.h"
#include "LGameplayInterface.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
ULInteractionComponent::ULInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULInteractionComponent::PrimaryInteraction()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	FVector EyeLocation;
	FRotator EyeRotation;
	AActor* MyOwner = GetOwner();
	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);
	FVector End = EyeLocation + (EyeRotation.Vector() * 1000.0f);
	
	TArray<FHitResult> Hits;
	FCollisionShape Shape;
	float Radius = 30.0f;
	Shape.SetSphere(Radius);
	bool bBlocking = GetWorld()->SweepMultiByObjectType(Hits,EyeLocation,End,FQuat::Identity,ObjectQueryParams,Shape);
	FColor LineColor = bBlocking ? FColor::Green : FColor::Red;
	for (FHitResult Hit : Hits)
	{
		AActor* MyActor = Hit.GetActor();
		if (MyActor)
		{
			DrawDebugSphere(GetWorld(),Hit.ImpactPoint,Radius,32.0f,LineColor,false,2.0f,0.0f,2.0f);
			if (MyActor->Implements<ULGameplayInterface>())
			{
				APawn* MyPawn = Cast<APawn>(MyOwner);
				ILGameplayInterface::Execute_Interact(MyActor,MyPawn);
				break;
			}
		}
	}
	DrawDebugLine(GetWorld(),EyeLocation,End,LineColor,false,5.0f,0.0f,2.0f);
}

