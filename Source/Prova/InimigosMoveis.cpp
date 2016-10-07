// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "InimigosMoveis.h"
#include "MyCharacter.h"


// Sets default values
AInimigosMoveis::AInimigosMoveis()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	Root->OnComponentBeginOverlap.AddDynamic(this, &AInimigosMoveis::OnOverlapBegin);
	RootComponent = Root;
	side = 0;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AInimigosMoveis::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInimigosMoveis::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector LocalizacaoAtual = GetActorLocation();

	if (side==0) {
		float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
		LocalizacaoAtual.Y += DeltaHeight * 200.0f;
		RunningTime += DeltaTime;
		SetActorLocation(LocalizacaoAtual);
	}
	else if (side==1) {
		float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
		LocalizacaoAtual.Y -= DeltaHeight * 200.0f;
		RunningTime += DeltaTime;
		SetActorLocation(LocalizacaoAtual);
	}
	else if (side==2) {
		if (Cont>=0 && Cont<200) {
			LocalizacaoAtual.Y++;
			SetActorLocation(LocalizacaoAtual);
		}
		else if (Cont >= 200 && Cont<400) {
			LocalizacaoAtual.X++;
			SetActorLocation(LocalizacaoAtual);
		}
		else if (Cont >= 400 && Cont<600) {
			LocalizacaoAtual.X--;
			SetActorLocation(LocalizacaoAtual);
		}
		else if (Cont >= 600 && Cont<800) {
			LocalizacaoAtual.Y--;
			SetActorLocation(LocalizacaoAtual);
		}
		else {
			Cont = 0;
		}
		
	}
	Cont++;
	

}

void AInimigosMoveis::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetLife(MyCharacter->GetLife() - DamageAmount);
		MyCharacter->OnDeath();
		
	}


}
