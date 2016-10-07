// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "Canhao.h"
#include "ProjectileActor.h"


// Sets default values
ACanhao::ACanhao()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));

	RootComponent = Root;


	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);

	CountdownTime = 100.0f;

}

// Called when the game starts or when spawned
void ACanhao::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this,
		&ACanhao::TimerManager, 1.0f, true);
	
	
}

// Called every frame
void ACanhao::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	ACanhao::TimerManager();
	if (CountdownTime <= 0) {
		CountdownTime = 100.0f;
	}
}


void ACanhao::DropProjectile() {
	FActorSpawnParameters SpawnParameters;
	UWorld* World = GetWorld();
	if (World != nullptr) {
		FRotator Rotation = MeshComp->GetComponentRotation();
		AProjectileActor* Proj = World->SpawnActor<AProjectileActor>
			(GetActorLocation(), Rotation,
				SpawnParameters);
		if (Proj != nullptr) {
		
		}
	}
}


void ACanhao::TimerManager() {
	CountdownTime -= 1.0f;
	if (CountdownTime <= 0.0f) {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		ACanhao::DropProjectile();
	}
}
