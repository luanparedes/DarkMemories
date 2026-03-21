#include "UDebugUtils.h"
#include "Kismet/GameplayStatics.h"

void UUDebugUtils::DrawSphere(AActor* actor)
{
	DrawDebugSphere(actor->GetWorld(), actor->GetActorLocation(), 50.0f, 12, FColor::Blue, false, -1.f);
}

void UUDebugUtils::DrawLine(AActor* actor)
{
	APawn* player = UGameplayStatics::GetPlayerPawn(actor->GetWorld(), 0);
	DrawDebugLine(actor->GetWorld(), actor->GetActorLocation(), player->GetActorLocation(), FColor::Red, false, -1.f);
}

void UUDebugUtils::DrawBox(AActor* actor)
{
	DrawDebugBox(actor->GetWorld(), actor->GetActorLocation(), FVector(70, 70, 70), FColor::Emerald, false, -1.f);
}

void UUDebugUtils::DrawPoint(AActor* actor)
{
	APawn* player = UGameplayStatics::GetPlayerPawn(actor->GetWorld(), 0);
	DrawDebugPoint(actor->GetWorld(), player->GetActorLocation(), 18.f, FColor::Magenta, false, -1.f);
}
