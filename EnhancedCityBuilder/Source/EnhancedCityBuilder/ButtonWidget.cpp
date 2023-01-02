// Fill out your copyright notice in the Description page of Project Settings.
#include "ButtonWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MainPlayerController.h"

void UButtonWidget::SetData(int value)
{
	Text->SetText(FText::FromString(FString::FromInt(value)));
	BtnIndex = value;
}

void UButtonWidget::OnclickMyButton()
{
	AMainPlayerController* MyPc = Cast<AMainPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	MyPc->IndexOfCurrentSelectedBuilding = BtnIndex;
}

