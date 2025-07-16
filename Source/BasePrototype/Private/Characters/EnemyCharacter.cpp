// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EnemyCharacter.h"


#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/AttributeSet/BaseAttributeSet.h"
#include "BasePrototype/BasePrototype.h"


AEnemyCharacter::AEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UBaseAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>("AttributeSet");
}

void AEnemyCharacter::HighlightEnemy()
{
	bHighlighted = true;
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AEnemyCharacter::UnHighlightEnemy()
{
	bHighlighted = false;
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
