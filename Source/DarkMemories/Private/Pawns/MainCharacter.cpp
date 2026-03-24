// Copyright Sunnymoon Software.


#include "Pawns/MainCharacter.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(GetRootComponent());

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComp->SetupAttachment(CameraBoom);
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* playerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			subsystem->AddMappingContext(InputMapping, 0);
		}
	}
	
}

void AMainCharacter::Move(const FInputActionValue& Value)
{
	const float DirectionValue = Value.Get<float>();
	
	if (GetController() && (DirectionValue != 0.f))
	{
		FVector forward = GetActorForwardVector();
		AddMovementInput(forward, DirectionValue);

		UE_LOG(LogTemp, Warning, TEXT("Andou para a frente!"));
	}
}

void AMainCharacter::Look(const FInputActionValue& Value)
{
	if (const bool currentValue = Value.Get<bool>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Looking"));
		//MoveForward(FVector(12.f, 14.f, 18.f));
	}
}

void AMainCharacter::Jump(const FInputActionValue& Value)
{
	//IsJumping = true;
	if (const bool currentValue = Value.Get<bool>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Jumping"));
		//MoveForward(FVector(12.f, 14.f, 18.f));
	}
}

void AMainCharacter::JumpEnd(const FInputActionValue& Value)
{
	//IsJumping = false;
	if (const bool currentValue = Value.Get<bool>())
	{
		UE_LOG(LogTemp, Warning, TEXT("EndJump"));
		//MoveForward(FVector(12.f, 14.f, 18.f));
	}
}

void AMainCharacter::MoveForward(float value)
{
	if (GetController() && value != 0.f)
	{
		FVector forward = GetActorForwardVector();
		AddMovementInput(forward, value);

		UE_LOG(LogTemp, Warning, TEXT("Andou para a frente!"));
	}
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainCharacter::Move);
		enhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMainCharacter::Look);
		enhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AMainCharacter::Jump);
		enhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMainCharacter::JumpEnd);
	}
	//PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AMainCharacter::MoveForward);
}

