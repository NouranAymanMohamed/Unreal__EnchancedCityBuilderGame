// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "UIManager.generated.h"

UCLASS()
class ENHANCEDCITYBUILDER_API AUIManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUIManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UUserWidget* VerticalBoxReference;          //Reference to vertical box.

	UPROPERTY(EditAnywhere)
		UUserWidget* HorizontalBoxReference;    //Reference to horizontal box.
};
