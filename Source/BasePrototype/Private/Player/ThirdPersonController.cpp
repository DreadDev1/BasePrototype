// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ThirdPersonController.h"

#include "EnhancedInputComponent.h"
#include "Interactions/HighlightInterface.h"
#include "Kismet/GameplayStatics.h"

AThirdPersonController::AThirdPersonController()
{
	PrimaryActorTick.bCanEverTick = true;
	TraceLength = 500.0;
}

void AThirdPersonController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	TraceForItem();
}

void AThirdPersonController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AThirdPersonController::Interact);
}

void AThirdPersonController::Interact()
{
	UE_LOG(LogTemp, Log, TEXT("Primary Interact"))
}

void AThirdPersonController::TraceForItem()
{
	if (!IsValid(GEngine) || !IsValid(GEngine->GameViewport)) return;
	FVector2D ViewportSize;
	GEngine->GameViewport->GetViewportSize(ViewportSize);
	const FVector2D ViewportCenter = ViewportSize / 2.f;
	FVector TraceStart;
	FVector Forward;
	if (!UGameplayStatics::DeprojectScreenToWorld(this, ViewportCenter, TraceStart, Forward)) return;

	const FVector TraceEnd = TraceStart + Forward * TraceLength;
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ItemTraceChannel);

	LastActor = ThisActor;
	ThisActor = HitResult.GetActor();

	if (ThisActor == LastActor) return;

	if (ThisActor.IsValid())
	{
		
		UE_LOG(LogTemp, Warning, TEXT("Started tracing a new actor."))
	}

	if (LastActor.IsValid())
	{
		
		UE_LOG(LogTemp, Warning, TEXT("Stopped tracing last actor."))
	}
}
