// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "Porta.h"
#include "MyCharacter.h"



// Sets default values
APorta::APorta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshDoor(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Door.SM_Door'"));
	if (MeshDoor.Succeeded()) {
		Door->SetStaticMesh(MeshDoor.Object);
	}
	
	RootComponent = Door;

	PortasNum = 0;
}

// Called when the game starts or when spawned
void APorta::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void APorta::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	

}

void APorta::SetPortasNum(int NewPorta) {
	PortasNum = NewPorta;
}

int APorta::GetPortasNum() {
	return PortasNum;

}

void APorta::DestroyDoor(int NumPorta) {
	if (PortasNum == NumPorta) {
		Destroy();
	}
	
}

