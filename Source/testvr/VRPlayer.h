// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SteamVRChaperoneComponent.h"
#include "VRPlayer.generated.h"

UCLASS()
class TESTVR_API AVRPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVRPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float Reputation;
public:	
	UFUNCTION(BlueprintCallable)
		void LoseReputation();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float value);
	void MoveRight(float value);

	UPROPERTY(BlueprintReadOnly, Category = "VRPawn")
	USteamVRChaperoneComponent* ChaperoneComponent;
};
