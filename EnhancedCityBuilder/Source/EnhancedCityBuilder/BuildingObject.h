// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainPlayerController.h"
#include "BuildingObject.generated.h"

UCLASS()
class ENHANCEDCITYBUILDER_API ABuildingObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void OnclickBuildingObject();

	void ScaleUpBuilding();
	void ScaleDownBuilding();
	void RotateBuilding();
	void DeleteBuilding();

	AMainPlayerController* MainPlayerController;

private:
	UStaticMeshComponent* StaticMeshComponent;
};
