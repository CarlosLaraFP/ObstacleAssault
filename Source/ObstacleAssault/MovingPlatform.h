// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"


UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Translation")
	double ReverseDistance = 0.0;

	// VisibleAnywhere = readonly in the editor

	UPROPERTY(EditAnywhere, Category="Translation")
	FVector Velocity = FVector(0, 0, 0); // UE5 uses centimeters

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity; // default (0, 0, 0)

	FVector StartLocation;

	void Move(float DeltaTime);
	void Rotate(float DeltaTime);

	bool ShouldReverse() const;
};
