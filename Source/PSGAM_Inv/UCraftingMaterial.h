// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UItemBase.h"
#include "UCraftingMaterial.generated.h"

/**
 * 
 */
UCLASS()
class PSGAM_INV_API UUCraftingMaterial : public UUItemBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Material settings")
	int32 Quantity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Material settings", meta = (ClampMin = "1"))
	int32 MaxStackSize;
};
