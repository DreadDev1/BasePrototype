// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "TopDownCharacter.generated.h"

UCLASS()
class BASEPROTOTYPE_API ATopDownCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATopDownCharacter();
	void SetTopDownView();
	FVector NewLocation = FVector(0.f, 0,600.f);
	FRotator NewRotation = FRotator(120.0f, 0.0f, 0.0f);
};
