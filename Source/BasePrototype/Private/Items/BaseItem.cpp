// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/BaseItem.h"


// Sets default values
ABaseItem::ABaseItem()
{
	
}

void ABaseItem::HighlightItem()
{
	IHighlightInterface::HighlightItem();
}

void ABaseItem::UnHighlightItem()
{
	IHighlightInterface::UnHighlightItem();
}


