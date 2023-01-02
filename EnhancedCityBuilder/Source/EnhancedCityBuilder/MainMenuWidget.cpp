// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/VerticalBoxSlot.h"
#include "ButtonWidget.h"
#include "MainMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MainPlayerController.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//Get reference to player controller. 
	AMainPlayerController* mainPlayerController = Cast<AMainPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	
	//Get number of buildings instantiate a button foreach of them.
	int NumberOfElements = mainPlayerController->BuildingsToSpawn.Num();

	if (ButtonWidgetReference)
	{
		for (int i = 0; i < NumberOfElements; i++) //populate vertical box with buttons based on number of buildings to spawn.
		{
			UUserWidget* Widget = CreateWidget(this, ButtonWidgetReference);        //create button widget.
			UVerticalBoxSlot* slot = DynamicVerticalBox->AddChildToVerticalBox(Widget);  //add button to vertical box.
			slot->SetSize(ESlateSizeRule::Type::Fill);                             
			UButtonWidget* ButtonWidget = Cast<UButtonWidget>(Widget);             
			ButtonWidget->SetData(i);                                              //update button's text.
		}
	}

}