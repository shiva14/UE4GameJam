// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemInterface.h"

#include "Item.generated.h"

// Example Materials
UENUM(Blueprintable)
enum class MaterialType : uint8
{
	Copper,
	Iron,
	Gold,
	Max
};

// Example Weapons
UENUM(Blueprintable)
enum class WeaponType : uint8
{
	Sword,
	Sickle,
	Axe,
	None,
	Max
};

UENUM(Blueprintable)
enum class ItemState : uint8
{
	Ore,
	Ingot,
	DullWeapon,
	SharpWeapon,
	Max
};

UCLASS()
class TESTVR_API AItem : public AActor, public IItemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Change Item States

	//UFUNCTION(BlueprintCallable)
	//void SetWeapon(WeaponType type);


// Ore State
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OreState)
	float maxHeatRequired= 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OreState)
	float qualityDecreaseRate = 1.f; // Per 1.f extra heat.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OreState)
	float ingotQuality = 1.f; //

	UFUNCTION(BlueprintCallable)
	float GetCurrentHeatPercentage() { return mCurrentHeat / maxHeatRequired; }

	UFUNCTION(BlueprintCallable)
	bool IsInFurnace() { return furnaceId > -1; }

	UFUNCTION(BlueprintCallable)
	int GetFurnaceSlot() { return furnaceId; }

	int furnaceId = -1;

	// increases heat and returns if can change to ingot.
	bool IncreaseHeat(float heat);
	void CalculateIngotQuality();


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ore State")
	void SetToIngot();
	virtual void SetToIngot_Implementation() override;

private:	
	float mCurrentHeat = 0.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

// Ingot State
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ore State")
	void SetToWeapon(float quality);
	virtual void SetToWeapon_Implementation(float quality) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OreState)
	float weaponQuality = 1.f; //


// Weapon State
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grind")
	float mProcessAmount = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grind")
	float mCrackAmount = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = OreState)
	float grindQuality = 1.f; //

// Global State
public: 
	
	// Setters
	UFUNCTION(BlueprintCallable)
	void SetQuality(float quality) { mItemQuality = quality; }
	UFUNCTION(BlueprintCallable)
	void AddProcess(float process) { mProcessAmount = FMath::Min(mProcessAmount + process, 1.0f); }
	UFUNCTION(BlueprintCallable)
	void AddCrack(float crack) { mCrackAmount = FMath::Min(mCrackAmount + crack, 1.0f); }
	UFUNCTION(BlueprintCallable)
	void SetState(ItemState state) { mState = state; }
	UFUNCTION(BlueprintCallable)
	void SetWeaponType(WeaponType type) { mWeaponType = type; }
	UFUNCTION(BlueprintCallable)
	void SetMaterialType(MaterialType type) { mMaterialType = type; }
	UFUNCTION(BlueprintCallable)
	void SetGrab(bool grab) { mIsGrabbed = grab; }
	UFUNCTION(BlueprintCallable)
	void SetGrabbable(bool grab) { mCanBeGrabbed = grab; }

	// Getters
	UFUNCTION(BlueprintCallable)
	float GetQuality() { return mItemQuality; }
	UFUNCTION(BlueprintCallable)
	ItemState GetState() { return mState; }
	UFUNCTION(BlueprintCallable)
	float GetProcess() { return mProcessAmount; }
	UFUNCTION(BlueprintCallable)
	float GetCrack() { return mCrackAmount; }
	UFUNCTION(BlueprintCallable)
	WeaponType GetWeaponType() { return mWeaponType; }
	UFUNCTION(BlueprintCallable)
	MaterialType GetMaterialType() { return mMaterialType; }
	UFUNCTION(BlueprintCallable)
	bool GetGrab() { return mIsGrabbed; }
	UFUNCTION(BlueprintCallable)
	bool CanBeGrabbed() { return mCanBeGrabbed; }


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		WeaponType mWeaponType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		MaterialType mMaterialType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		ItemState mState;
	

	float mItemQuality = 1.f;

	bool mIsGrabbed = false;
	bool mCanBeGrabbed = true;
};
