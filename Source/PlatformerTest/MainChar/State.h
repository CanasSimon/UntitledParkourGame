// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType, meta = (BitFlags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum EState
{
	None = 0,
	CanWallRun = 1u << 0u,
	WallRunning = 1u << 1u,
	WallRunningRight = 1u << 2u,
	WallRunningLeft = 1u << 3u,
	Sliding = 1u << 4u
}; ENUM_CLASS_FLAGS(EState)
