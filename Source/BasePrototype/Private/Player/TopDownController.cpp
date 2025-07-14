// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TopDownController.h"

ATopDownController::ATopDownController()
{
	bReplicates = true;
}

void ATopDownController::SetTopDownView()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
