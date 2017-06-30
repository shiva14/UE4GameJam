// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemInterface.h"

#include "Item.generated.h"

// Example Materials
enum class Material
{
	kCopper,
	kIron,
	kSteel,
	kMax
};

// Example Weapons
enum class WeaponType
{
	kSword,
	kAxe,
	kLance,
	kMax
};

enum class ItemState
{
	kOre,
	kSmelting,
	kIngot,
	kForging,
	kDullWeapon,
	kSharpening,
	kSharpWeapon,
	kMax
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

	// Grabbing
	virtual void Grab(USceneComponent* controller) override;
	virtual void Release() override;

	//Change Item States
	void SetIngot(USkeletalMeshComponent* mMesh, UMaterialInstanceDynamic* mMaterial);
	void SetWeapon(WeaponType type);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float mItemQuality;

	UPROPERTY(EditAnywhere)
	UMaterialInstanceDynamic* mMaterial;
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* mMesh;
	
	ItemState mState;
	WeaponType mWeaponType;
	Material mMaterialType;

};
