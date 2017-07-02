// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Monster.generated.h"

UCLASS()
class TESTVR_API AMonster : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMonster();

	UPROPERTY(EditAnywhere, Category = Behavior)
		class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, Category = Behavior)
		FVector StallLocation;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//UCharacterMovementComponent* Movement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
