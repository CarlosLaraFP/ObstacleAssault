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

void AMovingPlatform::Move(float DeltaTime)
{
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

void AMovingPlatform::Rotate(float DeltaTime)
{
	FRotator currentRotation = GetActorRotation();

	FString instanceName = GetName();

	double X = currentRotation.GetComponentForAxis(EAxis::Type::X);
	double Y = currentRotation.GetComponentForAxis(EAxis::Type::Y);
	double Z = currentRotation.GetComponentForAxis(EAxis::Type::Z);

	UE_LOG(LogTemp, Display, TEXT("The current rotation of %s is (%f, %f, %f)"), *instanceName, X, Y, Z);

	SetActorRotation(currentRotation);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->Move(DeltaTime);
	this->Rotate(DeltaTime);
}

