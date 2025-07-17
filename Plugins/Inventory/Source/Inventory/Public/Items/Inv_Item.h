// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inv_Item.generated.h"

UCLASS()
class INVENTORY_API AInv_Item : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInv_Item();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* ItemMesh;

};
