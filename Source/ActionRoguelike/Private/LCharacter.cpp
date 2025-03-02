#include "LCharacter.h"

#include <Actor.h>

#include "LInteractionComponent.h"
#include "LProjectileDash.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"


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

	AttackTimer = 0.0f;
	AttackTimeCount = 0.8f;
	BlockHoleTimer = 0.0f;
	BlockHoleTimeCount = 5.0f;
	bIsAttack = true;
	bIsBlockHole = true;

	DashTimer = 0.0f;
}

// Called when the game starts or when spawned
void ALCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (Crosshair_Widget != nullptr)
	{
	 	CrossWidget = CreateWidget<UUserWidget,UWorld>(this->GetWorld(),Crosshair_Widget);
		if (Crosshair_Widget != nullptr)
		{
			CrossWidget->AddToViewport();
		}
	}
}

// Called every frame
void ALCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timer(DeltaTime);

	if (bIsSpawnDash)
	{
		DashTimer += DeltaTime;
	}
	if (DashTimer >= DashLifeSpan)
	{
		SpawnPlayer();
	}
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
	PlayerInputComponent->BindAction("PrimaryBlackHole",IE_Pressed,this,&ALCharacter::PrimaryBlackHole);
	PlayerInputComponent->BindAction("PrimaryDash",IE_Pressed,this,&ALCharacter::PrimaryDash);

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
 	if (bIsAttack)
 	{
 		PlayAnimMontage(PrimaryInteractMontage);
 		GetWorldTimerManager().SetTimer(TimeHandle_PrimaryInteract,this, &ALCharacter::PrimaryInteract_TimeExpose,0.2f);
 		bIsAttack = false;
 	}
 
 }
 
 void ALCharacter::PrimaryInteract()
 {
 	if (InteractionComp)
 	{
 		InteractionComp->PrimaryInteraction();
 	}
 }
 
 void ALCharacter::PrimaryBlackHole()
 {
 	if (BlackHoleClass && bIsBlockHole)
 	{
 		FVector SpawnLocation = this->GetMesh()->GetSocketLocation("Muzzle_01");
 		FTransform SpawnTM = FTransform(this->GetControlRotation(), SpawnLocation);
 		FActorSpawnParameters SpawnParameters;
 		SpawnParameters.Instigator = this;
 		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
 		GetWorld()->SpawnActor<AActor>(BlackHoleClass, SpawnTM, SpawnParameters);
 		bIsBlockHole = false;
 	}
 }
 
 void ALCharacter::PrimaryDash()
 {
 	if (DashClass)
 	{
 		FVector SpawnLoc =  this->GetMesh()->GetSocketLocation("Muzzle_01");
 		FTransform SpawnTM = FTransform(this->GetControlRotation(), SpawnLoc);
 		FActorSpawnParameters SpawnParameters;
 		SpawnParameters.Instigator = this;
 		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
 	 	SpawnDash = Cast<ALProjectileDash>(GetWorld()->SpawnActor<AActor>(DashClass, SpawnTM, SpawnParameters));
 		bIsSpawnDash = SpawnDash ? true : false;
 		if (SpawnDash)
 		{
 			DashLifeSpan = SpawnDash->GetLifeSpan();
 		}
 	}
 }

void ALCharacter::SpawnPlayer()
{
	bIsSpawnDash = false;
	DashTimer = 0.0f;
	if (SpawnDash)
	{
		this->SetActorLocation(SpawnDash->GetActorLocation());
		this->SetActorRotation(FRotator(0.0f, SpawnDash->GetActorRotation().Yaw, 0.0f));
	}
}

void ALCharacter::PrimaryInteract_TimeExpose()
 {
 	FVector SpawnLoc = this->GetMesh()->GetSocketLocation("Muzzle_01");
 	FTransform SpawnTM = FTransform(this->GetControlRotation(), SpawnLoc);
 	FActorSpawnParameters SpawnParameters;
 	SpawnParameters.Instigator = this;
 	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
 	this->GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParameters);
 }
 
 void ALCharacter::Timer(float DeltaTime)
 {
 	if (!bIsAttack)
 	{
 		AttackTimer += DeltaTime;
 	}
 	if (!bIsBlockHole)
 	{
 		BlockHoleTimer += DeltaTime;
 	}
 	if (AttackTimer > AttackTimeCount)
 	{
 		bIsAttack = true;
 		AttackTimer = 0.0f;
 	}
 	if (BlockHoleTimer > BlockHoleTimeCount)
 	{
 		bIsBlockHole = true;
 		BlockHoleTimer = 0.0f;
 	}
 }