// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveZone.h"

#include "Components/DecalComponent.h"
#include "Mgfps/MgfpsCharacter.h"
#include "Mgfps/MgfpsGameMode.h"

// Sets default values
AObjectiveZone::AObjectiveZone()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlaComp"));

	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
	OverlapComp->SetBoxExtent(FVector(200.f));

	RootComponent = OverlapComp;

	OverlapComp->SetHiddenInGame(false);
	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::HandleOverlap);

	//Decal Component
	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->DecalSize = FVector(200.0f);
	DecalComp->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AObjectiveZone::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObjectiveZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("Overlapped"));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			10.f,
			FColor::Green,
			FString::Printf(TEXT("Overlapped")));
	}

	AMgfpsCharacter* MyPawn = Cast<AMgfpsCharacter>(OtherActor);

	if (MyPawn == nullptr)
	{
		return;
	}

	if (MyPawn->bIsCarryingObjective)
	{
		AMgfpsGameMode* GM = Cast<AMgfpsGameMode>(GetWorld()->GetAuthGameMode());

		if (GM)
		{
			GM->CompleteMission(MyPawn);
		}
	}
	
}




