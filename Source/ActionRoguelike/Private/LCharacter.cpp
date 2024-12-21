#include "LCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ALCharacter::ALCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("springArmComp"));
	springArmComp->bUsePawnControlRotation = true;
	springArmComp->SetupAttachment(RootComponent);

	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("cameraComp"));
	cameraComp->SetupAttachment(springArmComp);

	this->GetCharacterMovement()->bOrientRotationToMovement = true;
	this->bUseControllerRotationYaw = false; // 旋转控制
}

// Called when the game starts or when spawned
void ALCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALCharacter::MoveForward(float value){
	FRotator controlRot = this->GetControlRotation();
	controlRot.Pitch = 0.0f;
	controlRot.Roll = 0.0f;
    AddMovementInput(controlRot.Vector(), value);
}
void ALCharacter::MoveRight(float value){
	FRotator controlRot = this->GetControlRotation();
	controlRot.Pitch = 0.0f;
	controlRot.Roll = 0.0f;
	FVector rightVector = FRotationMatrix(controlRot).GetScaledAxis(EAxis::Y);
	AddMovementInput(rightVector, value);
}

void ALCharacter::PrimaryAttack()
{
	FVector spawnLoc = this->GetMesh()->GetSocketLocation("Muzzle_01");
	FTransform spawnTM = FTransform(this->GetActorRotation(), spawnLoc);
	FActorSpawnParameters spawnParmeters;
	spawnParmeters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	this->GetWorld()->SpawnActor<AActor>(projectileClass, spawnTM, spawnParmeters);
}

// Called to bind functionality to input
void ALCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&ALCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ALCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn",this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp",this,&APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("PrimaryAttack",IE_Pressed, this, &ALCharacter::PrimaryAttack);

}

