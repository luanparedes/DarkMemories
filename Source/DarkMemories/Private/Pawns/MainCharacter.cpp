// Copyright Sunnymoon Software.


#include "Pawns/MainCharacter.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(GetRootComponent());

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComp->SetupAttachment(CameraBoom);
}

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
	const FVector2D movementVector = Value.Get<FVector2D>();
	
	const FRotator rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, rotation.Yaw, 0.f);

	const FVector forwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector rightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(forwardDirection, movementVector.Y);
	AddMovementInput(rightDirection, movementVector.X);
}

void AMainCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D lookAxisVector = Value.Get<FVector2D>();

	AddControllerPitchInput(lookAxisVector.Y);
	AddControllerYawInput(lookAxisVector.X);
}

void AMainCharacter::EKeyPressed(const FInputActionValue& Value)
{

}

void AMainCharacter::Attack(const FInputActionValue & Value)
{

}

void AMainCharacter::Dodge(const FInputActionValue & Value)
{

}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMainCharacter::Move);
		enhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMainCharacter::Look);
		enhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMainCharacter::Jump);
		enhancedInputComponent->BindAction(EKeyAction, ETriggerEvent::Triggered, this, &AMainCharacter::EKeyPressed);
		enhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AMainCharacter::Attack);
		enhancedInputComponent->BindAction(DodgeAction, ETriggerEvent::Triggered, this, &AMainCharacter::Dodge);
	}
}

