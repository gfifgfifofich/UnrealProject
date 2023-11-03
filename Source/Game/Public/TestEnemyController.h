// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TestEnemyController.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API ATestEnemyController : public AAIController
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	ATestEnemyController();
	virtual void Tick(float DeltaSeconds) override;
	float timer = 1.0f;
	FVector trg;
};
