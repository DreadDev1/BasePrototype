// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

class UBaseHUDWidget;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class ABaseCharacter;

UCLASS()
class BASEPROTOTYPE_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ABasePlayerController();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, Category = "Base Prototype|Tracing|Trace Channel")
	TEnumAsByte<ECollisionChannel> ItemTraceChannel;
	UPROPERTY(EditAnywhere, Category = "Base Prototype|Tracing|Trace Channel")
	TEnumAsByte<ECollisionChannel> CharacterTraceChannel;
	TWeakObjectPtr<AActor> CurrentActor;
	TWeakObjectPtr<AActor> LastActor;
	TWeakObjectPtr<ABaseCharacter> CurrentCharacter;
	TWeakObjectPtr<ABaseCharacter> LastCharacter;

	void CreateHUDWidget();
	UPROPERTY(EditDefaultsOnly, Category="Base Prototype|Widgets")
	TSubclassOf<UBaseHUDWidget> HUDWidgetClass;
	UPROPERTY()
	TObjectPtr<UBaseHUDWidget> HUDWidget;
private:

#pragma region Mapping Context Actions
   	UPROPERTY(EditDefaultsOnly, Category = "Base Prototype|Inputs|Input Mapping Context")
   	TArray<TObjectPtr<UInputMappingContext>> DefaultIMCs;
   	
   	void Move(const FInputActionValue& InputActionValue);
    UPROPERTY(EditDefaultsOnly, Category="Base Prototype|Inputs|Input Actions")
    TObjectPtr<UInputAction> MoveAction;
    
    void Look(const FInputActionValue& InputActionValue);
    UPROPERTY(EditDefaultsOnly, Category="Base Prototype|Inputs|Input Actions")
    TObjectPtr<UInputAction> LookAction;
#pragma endregion Mapping Context Actions


	

};
