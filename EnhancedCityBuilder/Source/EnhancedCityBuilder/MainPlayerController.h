// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"


UCLASS()
class ENHANCEDCITYBUILDER_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	//* Input Binding Attributes *//
	virtual void SetupInputComponent() override;

	void OnClickLeftMouseButton();
	

	//* Building Spawning Attributes *//
    public:
	int IndexOfCurrentSelectedBuilding;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
    TArray<TSubclassOf<AActor>> BuildingsToSpawn;

	void SpawnBuilding(FVector Location);


	//* Cursor RayCast Attributes *//
	float CursorLocationX;                
	float CursorLocationY;               
	FHitResult CursorHitResult;         
	const bool bTraceComplex = false;
	void CastCursorRay();

    
	//* Control buttons *//
	UFUNCTION(BlueprintCallable)
		void OnclickScaleUpButton();

	UFUNCTION(BlueprintCallable)
		void OnclickScaleDownButton();

	UFUNCTION(BlueprintCallable)
		void OnclickScaleRotateButton();

	UFUNCTION(BlueprintCallable)
		void OnclickScaleDeleteButton();


	//* ActionType Attributes *//
    public:
	enum ActionType
	{
		ScaleUp,
		ScaleDown,
		Rotate,
		Delete
	};

	ActionType CurrentActionType;

	void SetActionType(ActionType actionType);

	AMainPlayerController::ActionType GetActionType();
};
