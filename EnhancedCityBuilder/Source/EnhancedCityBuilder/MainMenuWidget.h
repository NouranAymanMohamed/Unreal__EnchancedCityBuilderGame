// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class ENHANCEDCITYBUILDER_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
		UVerticalBox* DynamicVerticalBox;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> ButtonWidgetReference;
};
