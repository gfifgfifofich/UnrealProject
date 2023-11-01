// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "MIscObject.h"
#include "Kismet/GameplayStatics.h"
AGameCharacter::AGameCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(false); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	NeededCameraArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(0.f, 0.0f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AGameCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
	CameraBoom->SetUsingAbsoluteRotation(false);
	
	if (NeededCameraArmLength <= 100.0f)
		NeededCameraArmLength = 100.0f;
	CameraBoom->SetRelativeRotation(FRotator(-(1.0f-(100.0f / CameraBoom->TargetArmLength) + 0.1f) * 40.0f,0.0f , 0.0f));
	CameraBoom->TargetArmLength -= (CameraBoom->TargetArmLength - NeededCameraArmLength) * DeltaSeconds * 10.0f;
	
}


void AGameCharacter::SpawnActor()
{

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	FTransform tr = GetActorTransform();
	tr.SetLocation(tr.GetLocation() +  FVector(0, 0, 200));
	
	GetWorld()->SpawnActor<AActor>(actirBPToSpawn, tr,SpawnParams);
}
void AGameCharacter::DoSimthingWithObjects()
{

	TArray<AActor*> ActorsToFind;
	if (UWorld* World = GetWorld())
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMIscObject::StaticClass(), ActorsToFind);
		
	}
	for (AActor* TheAct : ActorsToFind)
	{
		TheAct->SetActorScale3D(TheAct->GetActorScale3D() + FVector(0.1f, 0.1f, 0.1f));
		
	}
}
void AGameCharacter::ZoomControl(float scroll)
{

	NeededCameraArmLength -= scroll * 100.0f;
}