// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Canhao.generated.h"

UCLASS()
class PROVA_API ACanhao : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACanhao();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
private:

	UPROPERTY(EditAnywhere)
		UBoxComponent* Root;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;

	void DropProjectile();
	FTimerHandle CountdownTimerHandle;
	float CountdownTime;
	void TimerManager();
	
};
