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

	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Warning, TEXT("Warning test"));
	UE_LOG(LogTemp, Error, TEXT("Error test: %f"), ReverseDistance);

	FString instanceName = GetActorNameOrLabel();

	UE_LOG(LogTemp, Display, TEXT("%s"), *instanceName);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	CurrentLocation += Velocity * DeltaTime;

	SetActorLocation(CurrentLocation);
	
	if (FVector::Distance(CurrentLocation, StartLocation) > ReverseDistance)
	{
		// Prevents overshooting and makes displacement precise
		StartLocation += Velocity.GetSafeNormal() * ReverseDistance;

		SetActorLocation(StartLocation);

		Velocity *= -1;
	}
}

