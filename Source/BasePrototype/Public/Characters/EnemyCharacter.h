// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Interactions/HighlightInterface.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class BASEPROTOTYPE_API AEnemyCharacter : public ABaseCharacter, public IHighlightInterface
{
	GENERATED_BODY()
public:
	AEnemyCharacter();
	virtual void HighlightEnemy() override;
	virtual void UnHighlightEnemy() override;

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

};
