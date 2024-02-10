// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SInteractorComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	//使SpringArm组件能同步角色的旋转
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject <UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	InsteractComp = CreateDefaultSubobject<USInteractorComponent>("InsteractComp");

	//禁止让角色同步控制器的旋转
	this->bUseControllerRotationYaw = false;
	//让角色的移动方向同步控制器的方向
	this->GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LineStart = GetActorLocation();
	// Offset to the right of pawn
	LineStart += GetActorRightVector() * 100.0f;
	// Set line end in direction of the actor's forward
	FVector ActorDirection_LineEnd = LineStart + (GetActorForwardVector() * 100.0f);
	// Draw Actor's Direction
	DrawDebugDirectionalArrow(GetWorld(), LineStart, ActorDirection_LineEnd, DrawScale, FColor::Yellow, false, 0.0f, 0, Thickness);

	FVector ControllerDirection_LineEnd = LineStart + (GetControlRotation().Vector() * 100.0f);
	// Draw 'Controller' Rotation ('PlayerController' that 'possessed' this character)
	DrawDebugDirectionalArrow(GetWorld(), LineStart, ControllerDirection_LineEnd, DrawScale, FColor::Green, false, 0.0f, 0, Thickness);
}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ASCharacter::PrimaryAttack);
	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &ASCharacter::PrimaryInteract);
}


void ASCharacter::MoveForward(float value)
{
	FRotator ControlRot = this->GetControlRotation();
	ControlRot.Roll = 0.0f;
	ControlRot.Pitch = 0.0f;

	AddMovementInput(ControlRot.Vector(), MoveSpeed * value);
}

void ASCharacter::MoveRight(float value)
{
	FRotator ControlRot = this->GetControlRotation();
	ControlRot.Roll = 0.0f;
	ControlRot.Pitch = 0.0f;
	FVector RightVec = UKismetMathLibrary::GetRightVector(ControlRot);
	AddMovementInput(RightVec, MoveSpeed * value);
}


void ASCharacter::PrimaryAttack()
{
	PlayAnimMontage(AttackAnim);
	this->GetWorldTimerManager().SetTimer(TimeHandle, this, &ASCharacter::PlayAttackAnim, 0.25f, false);
}

void ASCharacter::PlayAttackAnim()
{
	FVector handTM = this->GetMesh()->GetSocketLocation("Muzzle_01");
	FTransform ProjectileTM = FTransform(GetActorRotation(), handTM);

	FActorSpawnParameters Parameters;
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	this->GetWorld()->SpawnActor<AActor>(ProjectileClass, ProjectileTM, Parameters);
}

void ASCharacter::PrimaryInteract()
{
	if (InsteractComp) {
		InsteractComp->PrimaryInteract();
	}
}


