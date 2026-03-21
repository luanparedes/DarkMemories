

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UDebugUtils.generated.h"

UCLASS()
class DARKMEMORIES_API UUDebugUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static void DrawSphere(AActor* actor);
	static void DrawLine(AActor* actor);
	static void DrawBox(AActor* actor);
	static void DrawPoint(AActor* actor);
};
