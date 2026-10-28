// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UItemBase.h"
#include "UUsableItem.generated.h"

/**
 * 
 */
UCLASS()
class PSGAM_INV_API UUUsableItem : public UUItemBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Item")
	void Use(class AActor* User);
};
