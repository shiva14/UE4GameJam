// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AnvilNote.h"
#include "AnvilSongData.h"
#include "Anvil.generated.h"

UCLASS()
class TESTVR_API AAnvil : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAnvil();

	UFUNCTION(BlueprintCallable)
	void StartGame();
	void StopGame();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAnvilSongData> weapons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isIngotPlaced = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isGamePlaying = false;

protected:
	
	int32_t selectedWeapon;
	int32_t nextNote = 0;
	float nextNoteTime = 0.0f;
	float timePassed = 0.0f;
	float score = 0.0f;

	float noteSpawnHeight = 55.0f;
	float noteSpawnWidth = 40.0f;
	float noteSpawnLength = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USoundBase* hammerHitSound;

	class UAudioComponent* audioComponentHit;
	class UAudioComponent* audioComponentSong;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UClass* noteObj;
	TArray<AAnvilNote*> noteObjects;
	int32_t nextNoteToSpawn = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AItem* ingotOnAnvil;
};
