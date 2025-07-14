// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlayerController.h"
#include "TopDownController.generated.h"

class IHighlightInterface;
/**
 * 
 */
UCLASS()
class BASEPROTOTYPE_API ATopDownController : public ABasePlayerController
{
	GENERATED_BODY()
public:
	ATopDownController();
	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;

protected:

private:
	void CursorTrace();
	TScriptInterface<IHighlightInterface> LastActor;
	TScriptInterface<IHighlightInterface> ThisActor;

};
