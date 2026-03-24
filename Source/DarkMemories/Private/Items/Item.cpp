// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "UDebugUtils.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	Mesh->SetupAttachment(Capsule);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	//DRAW_SPHERE();
	//DrawDebugSphere(GetWorld(), GetActorLocation(), 100.f, 100, FColor::Blue, true);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GEngine)
	{
		FString message = FString::Printf(TEXT("Delta Time: %f"), DeltaTime);
		GEngine->AddOnScreenDebugMessage(1, 20.F, FColor::Blue, *message);
	}

	RunningTime += DeltaTime;

	AddActorLocalRotation(FQuat(RotationSpeed * DeltaTime));
	//float deltaZ = TransformedSine();

	//AddActorWorldOffset(FVector(0.f, 0.f, deltaZ));

	//UUDebugUtils::DrawSphere(this);
	//UUDebugUtils::DrawBox(this);
	//UUDebugUtils::DrawLine(this);
	//UUDebugUtils::DrawPoint(this);
}

float AItem::TransformedSine()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCosin()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

template<typename T>
inline T AItem::Average(T first, T second)
{
	return (first + second) / 2;
}