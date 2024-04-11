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
	int32 MyInt = 99;

	UPROPERTY(EditAnywhere)
	bool Next = true;

	UPROPERTY(EditAnywhere)
	TArray<uint32> MyVector = { 1, 2, 3, 4, 5 };

	UPROPERTY(EditAnywhere)
	float X = 16.99;

	UPROPERTY(EditAnywhere)
	float Y = 16.01;

	UPROPERTY(EditAnywhere)
	float XPlusY = 0;
};
