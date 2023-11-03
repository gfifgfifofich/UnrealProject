// Fill out your copyright notice in the Description page of Project Settings.

#include "TestEnemyController.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "../GameCharacter.h"
ATestEnemyController::ATestEnemyController()
{

}

void ATestEnemyController::BeginPlay()
{
	Super::BeginPlay();

}
void ATestEnemyController::Tick(float dt)
{
	Super::Tick(dt);

	timer -= dt;
	TArray<AActor*> Player;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGameCharacter::StaticClass(), Player);
	FVector dif = trg - Player[0]->GetActorLocation();
	if(dif.Length()>450)
	{
		trg = Player[0]->GetActorLocation();

		UAIBlueprintHelperLibrary::SimpleMoveToActor(this, Player[0]);
	}
}