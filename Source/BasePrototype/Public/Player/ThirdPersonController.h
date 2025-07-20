// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlayerController.h"
#include "ThirdPersonController.generated.h"

class IHighlightInterface;
class UInputAction;
class ABaseCharacter;
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

	UPROPERTY(EditDefaultsOnly, Category = "Base Prototype|Tracing|Trace Length")
	double TraceLength;
	void TraceForItem();
	void TraceForCharacter();
};
