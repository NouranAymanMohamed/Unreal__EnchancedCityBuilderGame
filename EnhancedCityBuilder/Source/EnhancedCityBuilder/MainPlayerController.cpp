// Fill out your copyright notice in the Description page of Project Settings.
#include "Components/InputComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MainPlayerController.h"

#pragma region Input Binding Region

//Called for action binding.
void AMainPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    InputComponent->BindAction("LeftMouseButton", EInputEvent::IE_Released, this, &AMainPlayerController::OnClickLeftMouseButton);
}

//Called when clicking left mouse button.
void AMainPlayerController::OnClickLeftMouseButton()
{
    CastCursorRay();
}

#pragma endregion

#pragma region Cursor RayCast Region

//Called to cast cursor ray.
void AMainPlayerController::CastCursorRay()
{
    if (GetWorld()->GetFirstPlayerController() != nullptr)
    {
        GetWorld()->GetFirstPlayerController()->GetMousePosition(AMainPlayerController::CursorLocationX, AMainPlayerController::CursorLocationY);

        FVector2D MousePosition(CursorLocationX, CursorLocationY);

        if (GetWorld()->GetFirstPlayerController()->GetHitResultAtScreenPosition(MousePosition, ECC_Visibility, AMainPlayerController::bTraceComplex, AMainPlayerController::CursorHitResult))
        {
            if ((AMainPlayerController::CursorHitResult.GetActor() != nullptr) && (AMainPlayerController::CursorHitResult.GetActor()->GetFName().ToString().Equals("Floor"))) //Check whether cursors hitted the floor.
            {
                SpawnBuilding(AMainPlayerController::CursorHitResult.Location);
            }
        }
    }
}

#pragma endregion

#pragma region Spawning Building Region

//Called to spawn a building at a specific location (hit position of cursor with ground).

void AMainPlayerController::SpawnBuilding(FVector Location) 
{
    AActor* CubeActor = GetWorld()->SpawnActor<AActor>(BuildingsToSpawn[IndexOfCurrentSelectedBuilding], Location, FRotator(0, 90, 0));
}

#pragma endregion

#pragma region Action Region

void AMainPlayerController::SetActionType(ActionType actionType)
{
    CurrentActionType = actionType;
}

AMainPlayerController::ActionType AMainPlayerController::GetActionType()
{
    return CurrentActionType;
}

#pragma endregion

#pragma region Control Buttons Region

//Called when ScaleUpButton is clicked.
void AMainPlayerController::OnclickScaleUpButton()
{
    CurrentActionType = AMainPlayerController::ActionType::ScaleUp;
}

//Called when ScaleDownButton is clicked.
void AMainPlayerController::OnclickScaleDownButton()
{
    CurrentActionType = AMainPlayerController::ActionType::ScaleDown;
}

//Called when ScaleRotateButton is clicked.
void AMainPlayerController::OnclickScaleRotateButton()
{
    CurrentActionType = AMainPlayerController::ActionType::Rotate;
}

//Called when ScaleDeleteButton is clicked.
void AMainPlayerController::OnclickScaleDeleteButton()
{
    CurrentActionType = AMainPlayerController::ActionType::Delete;
}

#pragma endregion
