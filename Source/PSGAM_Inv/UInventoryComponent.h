// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UInventoryComponent.generated.h"

class UUItemBase;

UENUM(BlueprintType)
enum class EInventoryType : uint8
{
	Backpack,
	Hotbar
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnInventoryUpdated, UUItemBase*, Item, int32, SlotIndex, EInventoryType, InventoryType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PSGAM_INV_API UUInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUInventoryComponent();

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdated OnInventoryUpdated;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void AddItemToInventory(TSubclassOf<class UUItemBase> Item);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	TArray<TObjectPtr<class UUItemBase>> BackpackItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	TArray<TObjectPtr<class UUItemBase>> HotbarItems;
};
