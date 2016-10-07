// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Porta.generated.h"

UCLASS()
class PROVA_API APorta : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APorta();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FORCEINLINE UStaticMeshComponent*GetDoor() const { return Door; }
	FORCEINLINE bool IsOpen()const { return Open; }
	FORCEINLINE void APorta::SetOpen(bool NewOpen) { Open = NewOpen; }


	void SetPortasNum(int NewPorta);
	int GetPortasNum();

	void DestroyDoor(int NumPorta);
private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent*Door;


	bool Open;	
	UPROPERTY(EditAnywhere)
	int PortasNum;

	
	
};
