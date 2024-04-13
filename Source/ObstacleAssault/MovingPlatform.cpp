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

bool AMovingPlatform::ShouldReverse() const 
{
	return FVector::Distance(GetActorLocation(), StartLocation) > ReverseDistance;
}

void AMovingPlatform::Move(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();

	CurrentLocation += Velocity * DeltaTime;

	SetActorLocation(CurrentLocation);

	if (ShouldReverse())
	{
		// Prevents overshooting and makes displacement precise
		StartLocation += Velocity.GetSafeNormal() * ReverseDistance;

		SetActorLocation(StartLocation);

		Velocity *= -1;
	}
}

void AMovingPlatform::Rotate(float DeltaTime)
{
	// Sets new rotation accounting for wraparounds
	AddActorLocalRotation(RotationVelocity * DeltaTime);

	FRotator CurrentRotation = GetActorRotation();

	double X = CurrentRotation.GetComponentForAxis(EAxis::Type::X);
	double Y = CurrentRotation.GetComponentForAxis(EAxis::Type::Y);
	double Z = CurrentRotation.GetComponentForAxis(EAxis::Type::Z);

	FString InstanceName = GetName();

	UE_LOG(LogTemp, Display, TEXT("The current rotation of %s is (%f, %f, %f)"), *InstanceName, X, Y, Z);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->Move(DeltaTime);
	this->Rotate(DeltaTime);
}

