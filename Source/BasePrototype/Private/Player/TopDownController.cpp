﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TopDownController.h"



#include "Interactions/HighlightInterface.h"

ATopDownController::ATopDownController()
{
	bReplicates = true;
}

void ATopDownController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void ATopDownController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	/**
	 * Line trace from cursor. There are several scenarios:
	  *  A. LastActor is null && ThisActor is null
	  *		- Do nothing
	  *	B. LastActor is null && ThisActor is valid
	 *		- Highlight ThisActor
	  *	C. LastActor is valid && ThisActor is null
	  *		- UnHighlight LastActor
	 *	D. Both actors are valid, but LastActor != ThisActor
	  *		- UnHighlight LastActor, and Highlight ThisActor
	  *	E. Both actors are valid, and are the same actor
	  *		- Do nothing
	  */

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// Case B
			ThisActor->HighlightEnemy();
		}
		else
		{
			// Case A - both are null, do nothing
		}
	}
	else // LastActor is valid
	{
		if (ThisActor == nullptr)
		{
			// Case C
			LastActor->UnHighlightEnemy();
		}
		else // both actors are valid
		{
			if (LastActor != ThisActor)
			{
				// Case D
				LastActor->HighlightEnemy();
				ThisActor->UnHighlightEnemy();
			}
			else
			{
				// Case E - do nothing
			}
		}
	}
}

void ATopDownController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}