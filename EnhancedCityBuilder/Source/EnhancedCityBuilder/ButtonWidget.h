// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "ButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class ENHANCEDCITYBUILDER_API UButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	//Properties.
	UPROPERTY(meta = (BindWidget))
		UButton* Btn;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* Text;

	int BtnIndex;

	//Methods.
	void SetData(int value);

	UFUNCTION(BlueprintCallable)
		void OnclickMyButton();
	
};
