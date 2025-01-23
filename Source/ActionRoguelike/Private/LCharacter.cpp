#include "LCharacter.h"

#include "LInteractionComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"



// Sets default values
ALCharacter::ALCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->bUsePawnControlRotation = true;	//玩家控制的旋转角度会影响摄像机的视角
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

	this->GetCharacterMovement()->bOrientRotationToMovement = true;	//角色的旋转方式为跟随其移动方向
	this->bUseControllerRotationYaw = false; // 角色的 Yaw（即旋转角度）不再直接由控制器的旋转来控制

	InteractionComp = CreateDefaultSubobject<ULInteractionComponent>(TEXT("InteractionComp"));

	PrimaryInteractMontage = CreateDefaultSubobject<UAnimMontage>(TEXT("PrimaryInteractMontage"));
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
	PlayAnimMontage(PrimaryInteractMontage);
	GetWorldTimerManager().SetTimer(TimeHandle_PrimaryInteract,this, &ALCharacter::PrimaryInteract_TimeExplose,0.2f);

}

void ALCharacter::PrimaryInteract()
{
	if (InteractionComp)
	{
		InteractionComp->PrimaryInteraction();
	}
}

void ALCharacter::PrimaryInteract_TimeExplose()
{
	FVector SpawnLoc = this->GetMesh()->GetSocketLocation("Muzzle_01");
	FTransform SpawnTM = FTransform(this->GetActorRotation(), SpawnLoc);
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	this->GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParameters);
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
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAction("PrimaryInteraction",IE_Pressed,this,&ALCharacter::PrimaryInteract);

}