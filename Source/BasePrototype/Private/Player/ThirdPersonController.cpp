// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ThirdPersonController.h"

#include "EnhancedInputComponent.h"
#include "Characters/BaseCharacter.h"
#include "Items/Components/Inv_ItemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/Base/BaseHUDWidget.h"

AThirdPersonController::AThirdPersonController()
{
	PrimaryActorTick.bCanEverTick = true;
	TraceLength = 500.0;
	ItemTraceChannel = ECC_GameTraceChannel1;
	CharacterTraceChannel = ECC_GameTraceChannel2;
}

void AThirdPersonController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	TraceForItem();
	TraceForCharacter();
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

	LastActor = CurrentActor;
	CurrentActor = HitResult.GetActor();

	if (!CurrentActor.IsValid())
	{
		if (IsValid(HUDWidget)) HUDWidget->HidePickupMessage();
	}
	
	if (CurrentActor == LastActor) return;

	if (CurrentActor.IsValid())
	{
		UInv_ItemComponent* ItemComponent = CurrentActor->FindComponentByClass<UInv_ItemComponent>();
		if (!IsValid(ItemComponent)) return;

		if (IsValid(HUDWidget)) HUDWidget->ShowPickupMessage(ItemComponent->GetPickupMessage());
	}

	if (LastActor.IsValid())
	{
		
		UE_LOG(LogTemp, Warning, TEXT("Stopped tracing last actor."))
	}
}

void AThirdPersonController::TraceForCharacter()
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
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, CharacterTraceChannel);

	LastCharacter = CurrentCharacter;
	CurrentCharacter = Cast<ABaseCharacter>(HitResult.GetActor());

	if (CurrentCharacter == LastCharacter) return;

	if (CurrentCharacter.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Started tracing a new character."));
	}

	if (LastCharacter.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Stopped tracing last character."));
	}
}