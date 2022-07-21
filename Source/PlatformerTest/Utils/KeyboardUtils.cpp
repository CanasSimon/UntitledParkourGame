// Fill out your copyright notice in the Description page of Project Settings.

#include "KeyboardUtils.h"
#include "GameFramework/InputSettings.h"
#include "PlatformerTest/Settings/LayoutOverrides.h"
#include "SDL.h"

int UKeyboardUtils::GetKeycodeFromName(const FString Name)
{
	return SDL_GetKeyFromName(TCHAR_TO_ANSI(*Name));
}

int UKeyboardUtils::GetScancodeFromName(const FString Name)
{
	return SDL_GetScancodeFromName(TCHAR_TO_ANSI(*Name));
}

FString UKeyboardUtils::GetNameFromKeycode(const int Code)
{
	return SDL_GetKeyName(Code); 
}

FString UKeyboardUtils::GetNameFromScancode(const int Code)
{
	return SDL_GetScancodeName(static_cast<SDL_Scancode>(Code));
}

ESupportedLayouts UKeyboardUtils::GetKeyboardLayout()
{
	// Get the keycodes from the keys located at Q, W and Y on a QWERTY keyboard and add them to identify the layout
	const int CodeToTest = SDL_GetKeyFromScancode(SDL_SCANCODE_Q) +
		SDL_GetKeyFromScancode(SDL_SCANCODE_W) +
		SDL_GetKeyFromScancode(SDL_SCANCODE_Y);
	switch (CodeToTest) // Magic numbers got from testing
	{
	case 353: return Qwerty;
	case 354: return Qwertz;
	case 340: return Azerty;
	case 185: return Dvorak;
	case 338: return Colemak;
	case 1073742155: return Bepo;
	case 1986: return Greek;
	default:
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Unknown, fallback to QWERTY"));
		return Qwerty;
	}
}

void UKeyboardUtils::PatchInputsFromLayout(const ESupportedLayouts Layout)
{
	FConfigFile InputConfig;
	InputConfig.Combine(UInputSettings::GetInputSettings()->GetDefaultConfigFilename());
	switch (Layout)
	{
	case Qwerty:
		InputConfig.Combine(GetDefault<UBUIInputSettings_QWERTZ>()->GetDefaultConfigFilename());
		break;
	case Qwertz:
		InputConfig.Combine(GetDefault<UBUIInputSettings_QWERTZ>()->GetDefaultConfigFilename());
		break;
	case Azerty:
		InputConfig.Combine(GetDefault<UBUIInputSettings_AZERTY>()->GetDefaultConfigFilename());
		break;
	case Dvorak:
		InputConfig.Combine(GetDefault<UBUIInputSettings_Dvorak>()->GetDefaultConfigFilename());
		break;
	case Colemak:
		InputConfig.Combine(GetDefault<UBUIInputSettings_Colemak>()->GetDefaultConfigFilename());
		break;
	case Bepo:
		InputConfig.Combine(GetDefault<UBUIInputSettings_Bepo>()->GetDefaultConfigFilename());
		break;
	case Greek:
		InputConfig.Combine(GetDefault<UBUIInputSettings_Greek>()->GetDefaultConfigFilename());
		break;
	default: ; // Invalid state, we do nothing since the game can still run
	}

	UPlayerInput PlayerInput;
	UE_LOG(LogTemp, Display, TEXT("%s"), *GetConfigFilename(&PlayerInput))
	
	//const FConfigSection* Section = InputConfig.Find("/Script/Engine.InputSettings");
	//if (Section)
	//{
	//	for (const auto& Pair : *Section)
	//	{
	//		FInputActionKeyMapping NewMapping;
	//		UE_LOG(LogTemp, Display, TEXT("%s"), *Pair.Value.GetValue())
	//	}
	//}
}

void UKeyboardUtils::KeyboardLayoutDebug()
{
	for (const char Ch : "aqwzy")
	{
		FString Message = FString::Printf(TEXT("%c: %i"), Ch, SDL_GetScancodeFromKey(Ch));
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, Message);
	}

	// Get the keycodes from the keys located a Q, W and Y on a QWERTY keyboard and add them to identify the layout
	const int CodeToTest = SDL_GetKeyFromScancode(SDL_SCANCODE_Q) +
		SDL_GetKeyFromScancode(SDL_SCANCODE_W) +
		SDL_GetKeyFromScancode(SDL_SCANCODE_Y);
	
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Result: %i"), CodeToTest));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, UInputSettings::GetInputSettings()->GetDefaultConfigFilename());
	switch (CodeToTest)
	{
	case 353:
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("QWERTY"));
		break;
	case 354:
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("QWERTZ"));
		break;
	case 340:
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("AZERTY"));
		break;
	case 185:
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Dvorak"));
		break;
	case 338:
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Colemak"));
		break;
	case 1073742155:
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Bépo"));
		break;
	case 1986:
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Greek"));
		break;
	default:
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Uknown, fallback to QWERTY"));
		break;
	}
}
