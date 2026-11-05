// Fill out your copyright notice in the Description page of Project Settings.


#include "UInventoryComponent.h"
#include "UUsableItem.h"
#include "UCraftingMaterial.h"

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

bool UUInventoryComponent::AddItemToInventory(TSubclassOf<UUItemBase> Item)
{
    if (!Item)
    {
        return false;
    }

	if (Item->IsChildOf(UUUsableItem::StaticClass())) {
		for(auto& Slot : HotbarItems) {
			if (!Slot) {
				auto* UsableItem = NewObject<UUUsableItem>(this, Item);
				Slot = UsableItem;
				OnUsableItemPickedUp.Broadcast(UsableItem, &Slot - &HotbarItems[0], EInventoryType::Hotbar);
				return true;
			}
		}
		for (auto& Slot : BackpackItems) {
			if (!Slot) {
				auto* UsableItem = NewObject<UUUsableItem>(this, Item);
				Slot = UsableItem;
				OnUsableItemPickedUp.Broadcast(UsableItem, &Slot - &BackpackItems[0], EInventoryType::Backpack);
				return true;
			}
		}
		return false; // No empty slot found in either Hotbar or Backpack
	}

	for(auto& Slot : BackpackItems) {
		if (!Slot) {
			auto* CraftingMat = NewObject<UUCraftingMaterial>(this, Item);
			Slot = CraftingMat;
			OnCraftingMaterialPickedUp.Broadcast(CraftingMat, CraftingMat->Quantity, &Slot - &BackpackItems[0]);	
			return true;
		}
		if(Slot->GetClass() == Item) {
			// Assuming the item has a Quantity property
			if (auto CraftingMat = Cast<UUCraftingMaterial>(Slot)) {
				if (CraftingMat->Quantity < CraftingMat->MaxStackSize) {
					CraftingMat->Quantity++;
					OnCraftingMaterialPickedUp.Broadcast(Cast<UUCraftingMaterial>(Slot.Get()), CraftingMat->Quantity, &Slot - &BackpackItems[0]);
					return true;
				}
			}
		}
	}
	return false;
}

