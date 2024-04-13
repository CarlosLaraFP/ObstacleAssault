// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teleporter.generated.h"

UCLASS()
class OBSTACLEASSAULT_API ATeleporter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleporter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Teleportation")
	ATeleporter* DestinationTeleporter;

	/*
		Macro to ensure it can interact with Unreal's reflection system, which is necessary for binding in Blueprints or calling from other parts of the engine.
		Function to handle overlap, set to virtual to allow overrides if needed.
		For handling overlaps and binding events in Blueprints, BlueprintCallable allows the function to be called from Blueprint nodes.
	*/
	UFUNCTION(BlueprintCallable, Category="Teleportation")
	virtual void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComponent, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComponent, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult
	);

private:
	UFUNCTION()
	void EnableTeleport();

	UPROPERTY(EditAnywhere, Category = "Teleportation")
	bool CanTeleport = true;

	// Timer handle for managing teleport availability
	FTimerHandle TeleportTimerHandle;
};
