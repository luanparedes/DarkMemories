// Copyright Sunnymoon Software.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Bird.generated.h"

class UCapsuleComponent;
class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class DARKMEMORIES_API ABird : public APawn
{
	GENERATED_BODY()

public:
	ABird();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere)
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction;

	virtual void BeginPlay() override;
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};
