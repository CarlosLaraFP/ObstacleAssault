// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	// As we subtract, X gets more positive until it crosses threshold X, and vice-versa.
	if (CurrentLocation.X >= ReverseThreshold.X || CurrentLocation.X <= ReverseThreshold.Y)
	{
		Displacement *= -1;
	}

	CurrentLocation.X += Displacement;

	SetActorLocation(CurrentLocation);
}

