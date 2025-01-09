// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TASK5_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int32 createEvent();
	float distance(FVector2D first, FVector2D second);
	
	void move();
	int32 step();


private:
	FVector2D Start;
	FVector2D Current;
	int32 evCnt;
	int totgDist;
};
