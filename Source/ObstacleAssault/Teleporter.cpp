// Fill out your copyright notice in the Description page of Project Settings.

#include "Teleporter.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"


// Sets default values
ATeleporter::ATeleporter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATeleporter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeleporter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATeleporter::OnOverlapBegin(
    UPrimitiveComponent* OverlappedComp, 
    AActor* OtherActor, 
    UPrimitiveComponent* OtherComp, 
    int32 OtherBodyIndex, 
    bool bFromSweep, 
    const FHitResult& SweepResult
) {
    if (OtherActor != nullptr && OtherActor != this && CanTeleport && DestinationTeleporter != nullptr)
    {
        ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);

        if (PlayerCharacter != nullptr)
        {
            FVector DestinationLocation = DestinationTeleporter->GetActorLocation();

            PlayerCharacter->SetActorLocation(DestinationLocation);

            // Disable further teleportation
            //CanTeleport = false;
            //DestinationTeleporter->CanTeleport = false;

            // Set timers to re-enable teleportation
            //GetWorld()->GetTimerManager().SetTimer(TeleportTimerHandle, this, &ATeleporter::EnableTeleport, 10.0f);
            //GetWorld()->GetTimerManager().SetTimer(DestinationTeleporter->TeleportTimerHandle, DestinationTeleporter, &ATeleporter::EnableTeleport, 10.0f);
        }
    }
}

void ATeleporter::EnableTeleport()
{
    CanTeleport = true;
}
