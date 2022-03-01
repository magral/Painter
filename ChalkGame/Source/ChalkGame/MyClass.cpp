// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyClass.h"
#include "RendererInterface.h"
#include "Engine/TextureRenderTarget2D.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include <map>
#include <string>
#include "Math/Color.h"
#include "Kismet/KismetMathLibrary.h"
#include <Runtime/Engine/Classes/Kismet/KismetRenderingLibrary.h>
#include <Runtime/Engine/Classes/Kismet/KismetMaterialLibrary.h>

MyClass::MyClass(UTextureRenderTarget2D* texture, UMaterialInterface* material)
{
	Texture = texture;
	Material = material;
}


void MyClass::CreateInitialRenderTarget() {
	Texture->UpdateResourceImmediate(true);
	Brush = UMaterialInstanceDynamic::Create(Material, this);
}

void MyClass::LineTraceFromCamera() {

	// Get viewport size
	FVector2D result = FVector2D(1, 1);
	
	if (GEngine && GEngine->GameViewport) {
		GEngine->GameViewport->GetViewportSize(result);
	}

	// Get Screen center plus cross hair material offset
	float adjustedX = result.X / 2 + 8.0;
	float adjustedY = result.Y / 2 + 26.0;

	result.X = adjustedX;
	result.Y = adjustedY;

	APlayerController* player = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	FVector worldPosition = FVector(1, 1, 1);
	FVector worldDirection = FVector(1, 1, 1);

	UGameplayStatics::DeprojectScreenToWorld(player, result, worldPosition, worldDirection);
	worldDirection *= 50000;
	
	// Line Trace from this object
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	RV_TraceParams.bTraceComplex = true;
	
	FHitResult RV_Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(
		RV_Hit,        //result
		worldPosition,    //start
		worldDirection, //end
		ECC_Pawn, //collision channel
		RV_TraceParams
	);

	if (RV_Hit.bBlockingHit == true) {
		// We hit something and should do something
		FString actorName = RV_Hit.GetActor()->GetName();
		
		// We need a render target per material, store them in a map so we do not keep
		// making new one's everytime
		if (NameToRenderTarget.count(actorName) > 0) {
			UTextureRenderTarget2D* renderTarget = NameToRenderTarget[actorName];
			FVector2D uvHit = FVector2D(1, 1);
			UGameplayStatics::FindCollisionUV(RV_Hit, 0, uvHit);
			FVector uvHitVector = FVector(uvHit.X, uvHit.Y, 0);
			FLinearColor linearColor = UKismetMathLibrary::Conv_VectorToLinearColor(uvHitVector);
			Brush->SetVectorParameterValue("uvTransform", linearColor);

			// Here we sample the UVs to get 2 vectors on the object we're hitting
			// We use the cross product of these to get a 3rd vector which we know is tangential
			// to the surface of what we're hitting. Using all this we can find the proper squash and scale
			// for our painting texture. So it doesn't look distorted. 

			FRandomStream randomStream = UKismetMathLibrary::MakeRandomStream(0);
			FVector randomizedVectorA = UKismetMathLibrary::RandomUnitVectorFromStream(randomStream);
			FVector randomizedVectorB = UKismetMathLibrary::RandomUnitVectorFromStream(randomStream);

			FVector crossedVectorA = UKismetMathLibrary::Cross_VectorVector(randomizedVectorA, RV_Hit.Normal);
			FVector crossedVectorB = UKismetMathLibrary::Cross_VectorVector(randomizedVectorB, RV_Hit.Normal);

			// Technically the vectors out of the cross product should be normalized, but this is 
			// a test project anyways so just to be safe we normalize
			UKismetMathLibrary::Vector_Normalize(crossedVectorA);
			UKismetMathLibrary::Vector_Normalize(crossedVectorB);

			// Scale the vector
			crossedVectorA *= 25;
			crossedVectorB *= 25;

			// Add to the original location and make a new hit result, which we'll then
			// use to find the collision UVs again
			FVector finalizedVectorA = RV_Hit.Location + crossedVectorA;
			FVector finalizedVectorB = RV_Hit.Location + crossedVectorB;

			FHitResult hitResultA = UGameplayStatics::MakeHitResult(false, false, 0, 0, finalizedVectorA, {}, {}, {}, {}, NULL, RV_Hit.Component.Get(), "", 0, 0, RV_Hit.FaceIndex, {}, {});
			FHitResult hitResultB = UGameplayStatics::MakeHitResult(false, false, 0, 0, finalizedVectorB, {}, {}, {}, {}, NULL, RV_Hit.Component.Get(), "", 0, 0, RV_Hit.FaceIndex, {}, {});

			FVector2D finalUVA = FVector2D(1, 1);
			FVector2D finalUVB = FVector2D(1, 1);
			UGameplayStatics::FindCollisionUV(hitResultA, 0, finalUVA);
			UGameplayStatics::FindCollisionUV(hitResultB, 0, finalUVB);

			// If we take these two final vectors, subtract the original hit from them, add them back and find the distance
			// we can determine the proper scale for our texture, so it remains consistent across different objects,
			// even if the material is stretched differently.
			FVector2D subtractedVectorA = UKismetMathLibrary::Subtract_Vector2DVector2D(uvHit, finalUVA);
			FVector2D subtractedVectorB = UKismetMathLibrary::Subtract_Vector2DVector2D(uvHit, finalUVB);

			FVector2D combinedVectors = UKismetMathLibrary::Add_Vector2DVector2D(subtractedVectorA, subtractedVectorB);
			float length = 1;
			FVector2D dir;
			UKismetMathLibrary::ToDirectionAndLength2D(combinedVectors, dir, length);

			// length becomes "scale" on our texture
			Brush->SetScalarParameterValue("scale", length);


			// Get the "squash" factor for our texture
			float dotVectorA = UKismetMathLibrary::DotProduct2D(subtractedVectorA, { 1, 0 });
			float dotVectorB = UKismetMathLibrary::DotProduct2D(subtractedVectorB, { 0, 1 });

			FVector squashVector = UKismetMathLibrary::MakeVector(dotVectorA, dotVectorB, 0);
			FLinearColor squashLinearColor = UKismetMathLibrary::Conv_VectorToLinearColor(squashVector);
			Brush->SetVectorParameterValue("squash", squashLinearColor);

			// Finally, draw the texture
			UKismetRenderingLibrary::DrawMaterialToRenderTarget(GetWorld(), NameToRenderTarget[actorName], Brush);
		} else {
			UTextureRenderTarget2D* createdRenderTarget = UKismetRenderingLibrary::CreateRenderTarget2D(GetWorld(), 1024, 1024);
			NameToRenderTarget.insert(std::pair<FString, UTextureRenderTarget2D*> (actorName, createdRenderTarget));
			UMaterialInterface* material = RV_Hit.Component->GetMaterial(0);
			UMaterialInstanceDynamic* instancedMaterial = UKismetMaterialLibrary::CreateDynamicMaterialInstance(GetWorld(), material);
			RV_Hit.Component->SetMaterial(0, instancedMaterial);
			instancedMaterial->SetTextureParameterValue("damageRT", createdRenderTarget);


			// COPIED FROM TRUE, GET SCALER VARS
			UTextureRenderTarget2D* renderTarget = NameToRenderTarget[actorName];
			FVector2D uvHit = FVector2D(1, 1);
			UGameplayStatics::FindCollisionUV(RV_Hit, 0, uvHit);
			FVector uvHitVector = FVector(uvHit.X, uvHit.Y, 0);
			FLinearColor linearColor = UKismetMathLibrary::Conv_VectorToLinearColor(uvHitVector);
			Brush->SetVectorParameterValue("uvTransform", linearColor);

			// Here we sample the UVs to get 2 vectors on the object we're hitting
			// We use the cross product of these to get a 3rd vector which we know is tangential
			// to the surface of what we're hitting. Using all this we can find the proper squash and scale
			// for our painting texture. So it doesn't look distorted. 

			FRandomStream randomStream = UKismetMathLibrary::MakeRandomStream(0);
			FVector randomizedVectorA = UKismetMathLibrary::RandomUnitVectorFromStream(randomStream);
			FVector randomizedVectorB = UKismetMathLibrary::RandomUnitVectorFromStream(randomStream);

			FVector crossedVectorA = UKismetMathLibrary::Cross_VectorVector(randomizedVectorA, RV_Hit.Normal);
			FVector crossedVectorB = UKismetMathLibrary::Cross_VectorVector(randomizedVectorB, RV_Hit.Normal);

			// Technically the vectors out of the cross product should be normalized, but this is 
			// a test project anyways so just to be safe we normalize
			UKismetMathLibrary::Vector_Normalize(crossedVectorA);
			UKismetMathLibrary::Vector_Normalize(crossedVectorB);

			// Scale the vector
			crossedVectorA *= 25;
			crossedVectorB *= 25;

			// Add to the original location and make a new hit result, which we'll then
			// use to find the collision UVs again
			FVector finalizedVectorA = RV_Hit.Location + crossedVectorA;
			FVector finalizedVectorB = RV_Hit.Location + crossedVectorB;

			FHitResult hitResultA = UGameplayStatics::MakeHitResult(false, false, 0, 0, finalizedVectorA, {}, {}, {}, {}, NULL, RV_Hit.Component.Get(), "", 0, 0, RV_Hit.FaceIndex, {}, {});
			FHitResult hitResultB = UGameplayStatics::MakeHitResult(false, false, 0, 0, finalizedVectorB, {}, {}, {}, {}, NULL, RV_Hit.Component.Get(), "", 0, 0, RV_Hit.FaceIndex, {}, {});

			FVector2D finalUVA = FVector2D(1, 1);
			FVector2D finalUVB = FVector2D(1, 1);
			UGameplayStatics::FindCollisionUV(hitResultA, 0, finalUVA);
			UGameplayStatics::FindCollisionUV(hitResultB, 0, finalUVB);

			// If we take these two final vectors, subtract the original hit from them, add them back and find the distance
			// we can determine the proper scale for our texture, so it remains consistent across different objects,
			// even if the material is stretched differently.
			FVector2D subtractedVectorA = UKismetMathLibrary::Subtract_Vector2DVector2D(uvHit, finalUVA);
			FVector2D subtractedVectorB = UKismetMathLibrary::Subtract_Vector2DVector2D(uvHit, finalUVB);

			FVector2D combinedVectors = UKismetMathLibrary::Add_Vector2DVector2D(subtractedVectorA, subtractedVectorB);
			float length = 1;
			FVector2D dir;
			UKismetMathLibrary::ToDirectionAndLength2D(combinedVectors, dir, length);

			// length becomes "scale" on our texture
			Brush->SetScalarParameterValue("scale", length);


			// Get the "squash" factor for our texture
			float dotVectorA = UKismetMathLibrary::DotProduct2D(subtractedVectorA, { 1, 0 });
			float dotVectorB = UKismetMathLibrary::DotProduct2D(subtractedVectorB, { 0, 1 });

			FVector squashVector = UKismetMathLibrary::MakeVector(dotVectorA, dotVectorB, 0);
			FLinearColor squashLinearColor = UKismetMathLibrary::Conv_VectorToLinearColor(squashVector);
			Brush->SetVectorParameterValue("squash", squashLinearColor);

			// Finally, draw the texture
			UKismetRenderingLibrary::DrawMaterialToRenderTarget(GetWorld(), NameToRenderTarget[actorName], Brush);
		}
	}

	// do nothing if we didn't hit anything

}

MyClass::~MyClass()
{
}
