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

	UPROPERTY(EditAnywhere)
	double ReverseDistance = 0.0;

	// VisibleAnywhere = readonly in the editor

	UPROPERTY(EditAnywhere, Category="Physical Properties")
	FVector Velocity = FVector(0, 0, 0); // UE5 uses centimeters

private:
	FVector StartLocation;
};
