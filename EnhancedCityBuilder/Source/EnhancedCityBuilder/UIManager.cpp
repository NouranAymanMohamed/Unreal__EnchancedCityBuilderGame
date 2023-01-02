// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"

// Sets default values
AUIManager::AUIManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUIManager::BeginPlay()
{
	Super::BeginPlay();

	if (VerticalBoxReference)
	{
		VerticalBoxReference->AddToViewport(0); //Add vertical box to ViewPort.
	}	

	if (HorizontalBoxReference)
	{
		HorizontalBoxReference->AddToViewport(0); //Add horizontal Box to ViewPort.
	}
}

// Called every frame
void AUIManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




