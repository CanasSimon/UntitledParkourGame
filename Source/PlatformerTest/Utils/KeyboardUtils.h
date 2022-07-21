// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KeyboardUtils.generated.h"

UENUM(BlueprintType)
enum ESupportedLayouts
{
	Qwerty = 0,
	Qwertz = 1,
	Azerty = 2,
	Dvorak = 3,
	Colemak = 4,
	Bepo = 5,
	Greek = 6,
}; ENUM_CLASS_FLAGS(ESupportedLayouts)

/**
 * 
 */
UCLASS()
class PLATFORMERTEST_API UKeyboardUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static int GetKeycodeFromName(const FString Name);
	
	UFUNCTION(BlueprintCallable)
	static int GetScancodeFromName(const FString Name);
	
	UFUNCTION(BlueprintCallable)
	static FString GetNameFromKeycode(const int Code);
	
	UFUNCTION(BlueprintCallable)
	static FString GetNameFromScancode(const int Code);
	
	UFUNCTION(BlueprintCallable)
	static ESupportedLayouts GetKeyboardLayout();
	
	UFUNCTION(BlueprintCallable)
	static void PatchInputsFromLayout(ESupportedLayouts Layout);
	
	UFUNCTION(BlueprintCallable, meta=(DevelopmentOnly))
	static void KeyboardLayoutDebug();
};
