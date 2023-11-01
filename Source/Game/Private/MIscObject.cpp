// Fill out your copyright notice in the Description page of Project Settings.


#include "MIscObject.h"

// Sets default values
AMIscObject::AMIscObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add(FName("Pickup"));
	
}

// Called when the game starts or when spawned
void AMIscObject::BeginPlay()
{
	Super::BeginPlay();
	Tags.Add(FName("Pickup"));

}

// Called every frame
void AMIscObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

