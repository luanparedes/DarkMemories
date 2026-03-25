// Copyright Sunnymoon Software.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MainCharacter.generated.h"

class UCapsuleComponent;
class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class DARKMEMORIES_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Jump(const FInputActionValue& Value);
	void JumpEnd(const FInputActionValue& Value);

private:
	UPROPERTY(EditAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;
};
