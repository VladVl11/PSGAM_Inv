// Fill out your copyright notice in the Description page of Project Settings.


#include "UInventoryComponent.h"
#include "UUsableItem.h"

// Sets default values for this component's properties
UUInventoryComponent::UUInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UUInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	BackpackItems.SetNum(72); // Set the number of items in the inventory to 72
	HotbarItems.SetNum(6); // Set the number of items in the hotbar to 6
}


// Called every frame
void UUInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UUInventoryComponent::AddItemToInventory(TSubclassOf<UUItemBase> Item)
{
    if (!Item)
    {
        return;
    }

	if (Item->IsChildOf(UUUsableItem::StaticClass())) {
		for(auto& Slot : HotbarItems) {
			if (!Slot) {
				Slot = NewObject<UUItemBase>(this, Item);
				OnInventoryUpdated.Broadcast(Slot, &Slot - &HotbarItems[0], EInventoryType::Hotbar);
				return;
			}
		}
	}

	for(auto& Slot : BackpackItems) {
		if (!Slot) {
			Slot = NewObject<UUItemBase>(this, Item);
			OnInventoryUpdated.Broadcast(Slot, &Slot - &BackpackItems[0], EInventoryType::Backpack);
			return;
		}
	}
}

