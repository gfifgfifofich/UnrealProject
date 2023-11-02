// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameCharacter.generated.h"

UCLASS(Blueprintable)
class AGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGameCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void SpawnActor();

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void DoSimthingWithObjects();


	UFUNCTION(BlueprintCallable, Category = "Camera")
	void ZoomControl(float Scroll);

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> actirBPToSpawn;


	bool CameraRotationPressed = false;
	bool MovingControlsPressed = false;
private:

	float NeededCameraArmLength = 800.0f;

	FVector2D PrevMousePos = { 0.0f,0.0f };
	float PrevRotation = 0.0f;
	float TargetRotation = 0.0f;
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
};

