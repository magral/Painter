// Fill out your copyright notice in the Description page of Project Settings.


#include "Painter.h"

// Sets default values
APainter::APainter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APainter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APainter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APainter::Paint() {

}

