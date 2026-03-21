// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DarkMemories/DarkMemories.h"
#include "Components/CapsuleComponent.h"
#include "Item.generated.h"

UCLASS()
class DARKMEMORIES_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.75f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float TimeConstant = 1.f;

	UFUNCTION(BlueprintPure)
	float TransformedSine();

	UFUNCTION(BlueprintPure)
	float TransformedCosin();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rotator")
	FRotator RotationSpeed = FRotator(0,20,0);

	template<typename T>
	T Average(T first, T second);

private:
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sine Parameters", meta = (AllowPrivateAccess = "true"))
	float RunningTime = 1.f;
};
