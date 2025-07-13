// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "ThirdPersonCharacter.generated.h"

UCLASS()
class BASEPROTOTYPE_API AThirdPersonCharacter : public ABaseCharacter
{
	GENERATED_BODY()
public:
	AThirdPersonCharacter();
protected:
	UPROPERTY(VisibleAnywhere, Category = Camera)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* FollowCamera;
	FVector NewLocation = FVector(0.f, 0,74.f);
	
};
