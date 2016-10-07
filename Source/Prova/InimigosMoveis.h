// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "InimigosMoveis.generated.h"

UCLASS()
class PROVA_API AInimigosMoveis : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInimigosMoveis();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


private:
	UPROPERTY(EditAnywhere)
		UShapeComponent* Root;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(VisibleAnywhere, Category = Tick)
		float RunningTime;
	UPROPERTY(EditAnywhere)
		int side;

	UPROPERTY(EditAnywhere)
		float DamageAmount = 1;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	int Cont = 0;

	
};
