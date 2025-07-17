// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlayerController.h"
#include "ThirdPersonController.generated.h"

class IHighlightInterface;
UCLASS()
class BASEPROTOTYPE_API AThirdPersonController : public ABasePlayerController
{
	GENERATED_BODY()
	AThirdPersonController();
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupInputComponent() override;

private:
	void Interact();
	UPROPERTY(EditDefaultsOnly, Category = "Base Prototype|Inputs|Input Actions")
	TObjectPtr<UInputAction> InteractAction;

	void TraceForItem();
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	double TraceLength;
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TEnumAsByte<ECollisionChannel> ItemTraceChannel;

	TWeakObjectPtr<AActor> ThisActor;
	TWeakObjectPtr<AActor> LastActor;
};
