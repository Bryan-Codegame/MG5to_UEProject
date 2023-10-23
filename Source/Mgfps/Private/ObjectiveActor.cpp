// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveActor.h"

#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Mgfps/MgfpsCharacter.h"

// Sets default values
AObjectiveActor::AObjectiveActor()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetupAttachment(MeshComp);

	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	

}

// Called when the game starts or when spawned
void AObjectiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObjectiveActor::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PickUpFX, GetActorLocation());
}

void AObjectiveActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	AMgfpsCharacter* MyCharacter = Cast<AMgfpsCharacter>(OtherActor);

	if(MyCharacter)
	{
		MyCharacter->bIsCarryingObjective = true;
		Destroy();
	}

	PlayEffects();
}

