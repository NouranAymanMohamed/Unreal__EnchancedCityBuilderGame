// Fill out your copyright notice in the Description page of Project Settings.
#include "Kismet/GameplayStatics.h"
#include "MainPlayerController.h"
#include "BuildingObject.h"

// Sets default values
ABuildingObject::ABuildingObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABuildingObject::BeginPlay()
{
	Super::BeginPlay();

	//Get Player Controller.
	MainPlayerController = Cast<AMainPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	//Save static mesh component for efficiency
	TArray<UStaticMeshComponent*> StaticMeshComponents;
	GetComponents(StaticMeshComponents);

	if (StaticMeshComponents.Num() > 0)
	{
		StaticMeshComponent = StaticMeshComponents[0];
	}
}

// Called every frame
void ABuildingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//Called when mouse clicked this object.
void ABuildingObject::OnclickBuildingObject()
{
	switch (MainPlayerController->CurrentActionType)
	{
	     case AMainPlayerController::ActionType::ScaleUp:
		      ScaleUpBuilding();
		      break;
		 case AMainPlayerController::ActionType::ScaleDown:
			 ScaleDownBuilding();
			 break;
		 case AMainPlayerController::ActionType::Rotate:
			 RotateBuilding();
			 break;
		 case AMainPlayerController::ActionType::Delete:
			 DeleteBuilding();
			 break;

	    default:
		break;
	}
}


void ABuildingObject::ScaleUpBuilding()
{
	StaticMeshComponent->SetWorldScale3D(FVector(GetActorScale3D().X+1, GetActorScale3D().Y + 1, GetActorScale3D().Z+ 1));
}


void ABuildingObject::ScaleDownBuilding()
{
	StaticMeshComponent->SetWorldScale3D(FVector(GetActorScale3D().X - 1, GetActorScale3D().Y - 1, GetActorScale3D().Z - 1));
}


void ABuildingObject::RotateBuilding()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT(" Rotate Building !"));
}


void ABuildingObject::DeleteBuilding()
{
	Destroy();
}

