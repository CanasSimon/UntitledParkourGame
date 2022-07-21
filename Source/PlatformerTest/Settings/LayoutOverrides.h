// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/InputSettings.h"
#include "LayoutOverrides.generated.h"

/**
 * 
 */
UCLASS(config=InputQwertyOverrides, defaultconfig)
class UBUIInputSettings_QWERTY final : public UInputSettings {GENERATED_BODY()};

UCLASS(config=InputQwertzOverrides, defaultconfig)
class UBUIInputSettings_QWERTZ final : public UInputSettings {GENERATED_BODY()};

UCLASS(config=InputAzertyOverrides, defaultconfig)
class UBUIInputSettings_AZERTY final : public UInputSettings {GENERATED_BODY()};

UCLASS(config=InputDvorakOverrides, defaultconfig)
class UBUIInputSettings_Dvorak final : public UInputSettings {GENERATED_BODY()};

UCLASS(config=InputColemakOverrides, defaultconfig)
class UBUIInputSettings_Colemak final : public UInputSettings {GENERATED_BODY()};

UCLASS(config=InputBepoOverrides, defaultconfig)
class UBUIInputSettings_Bepo final : public UInputSettings {GENERATED_BODY()};

UCLASS(config=InputGreekOverrides, defaultconfig)
class UBUIInputSettings_Greek final : public UInputSettings {GENERATED_BODY()};
