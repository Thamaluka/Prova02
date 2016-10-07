// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "Coletaveis.h"
#include "MyCharacter.h"


// Sets default values
AColetaveis::AColetaveis()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &AColetaveis::OnOverlapBegin);
	RootComponent = Root;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(RootComponent);

	Victory = false;

}

// Called when the game starts or when spawned
void AColetaveis::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColetaveis::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void AColetaveis::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) {
		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetColeta(MyCharacter->GetColeta() + 1);

		if (MyCharacter->GetOpenDoor() == Coletavel) {
			if (Coletavel == 3) {
				MyCharacter->SetOpen(true);
			}
			Destroy();
		}
	}
}