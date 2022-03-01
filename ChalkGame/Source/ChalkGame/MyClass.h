// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RendererInterface.h"
#include <map>
#include <string>
/**
 * 
 */
class CHALKGAME_API MyClass : AActor
{
public:
	// Vars
	UTextureRenderTarget2D* Texture;
	UMaterialInterface* Material;
	UMaterialInstanceDynamic* Brush;
	std::map<FString, UTextureRenderTarget2D*> NameToRenderTarget;

	// Methods
	MyClass(UTextureRenderTarget2D* texture, UMaterialInterface* material);
	UFUNCTION(BlueprintCallable, Category="Painting")
	void LineTraceFromCamera();
	void CreateInitialRenderTarget();
	~MyClass();
};
