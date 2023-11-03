// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestEnemy.generated.h"

UCLASS(Blueprintable)
class GAME_API ATestEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	ATestEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float health = 10.0f;


	FVector Target;

	void SetTarget(FVector pos);

	void TakeDamage(float dmg);


};
