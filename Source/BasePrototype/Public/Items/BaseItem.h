// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactions/HighlightInterface.h"
#include "Items/Inv_Item.h"
#include "BaseItem.generated.h"

UCLASS()
class BASEPROTOTYPE_API ABaseItem : public AInv_Item, public IHighlightInterface
{
	GENERATED_BODY()

public:
	
	ABaseItem();
	/** Highlight Interface*/
	virtual void HighlightItem() override;
	virtual void UnHighlightItem() override;
	/** end Highlight Interface*/
};