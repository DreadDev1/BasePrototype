// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Inv_Item.h"


AInv_Item::AInv_Item()
{
	PrimaryActorTick.bCanEverTick = false;
	
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>("ItemMesh");
	ItemMesh->SetupAttachment(GetRootComponent());

	
}

