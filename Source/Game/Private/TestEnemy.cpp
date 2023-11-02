// Fill out your copyright notice in the Description page of Project Settings.


#include "TestEnemy.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
// Sets default values
ATestEnemy::ATestEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATestEnemy::SetTarget(FVector pos)
{
	Target = pos;
	//UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, pos);
	//UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, pos, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);

}