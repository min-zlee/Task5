// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Start = FVector2D(0.0f, 0.0f);
	Current = Start;
	evCnt = 0;
	totgDist = 0;
}


// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay(); 
	UE_LOG(LogTemp, Display, TEXT("시작점: (%.2f, %.2f)"), Current.X, Current.Y);
	move();
	UE_LOG(LogTemp, Display, TEXT("총 이벤트 발생 횟수: %d"), evCnt);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyActor::move() {
	for (int i = 0; i < 10; ++i) {
		Current.X += step();
		Current.Y += step();

		UE_LOG(LogTemp, Display, TEXT("현재 위치: (%.2f, %.2f)"), Current.X, Current.Y);

		if (createEvent()) {
			++evCnt;
		UE_LOG(LogTemp, Display, TEXT("!이벤트 발생!"));
		}
		else {
		UE_LOG(LogTemp, Display, TEXT("이벤트 발생 안함"));
		}

	}
}

int32 AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

int32 AMyActor::createEvent()
{
	return FMath::RandRange(0, 1);
}