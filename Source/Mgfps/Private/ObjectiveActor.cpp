// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveActor.h"

// Sets default values
AObjectiveActor::AObjectiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObjectiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObjectiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

