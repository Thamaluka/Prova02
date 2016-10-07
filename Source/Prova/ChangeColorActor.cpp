// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "ChangeColorActor.h"
#include "MyCharacter.h"


// Sets default values
AChangeColorActor::AChangeColorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &AChangeColorActor::OnOverlapBegin);
	
	Root->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/Preto.Preto'"));
	if (Material.Succeeded()) {
		MeshComp->SetMaterial(0, Material.Object);
	}
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AChangeColorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChangeColorActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


void AChangeColorActor::SetColor(int NewColor) {
	Color = NewColor;
}

int AChangeColorActor::GetColor() {
	return Color;
}

void AChangeColorActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	Color++;
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr)) {
		if (Color==1) {
			UMaterial* NewMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), NULL, TEXT("Material'/Game/StarterContent/Materials/vermelho.vermelho'")));
			if (NewMaterial != nullptr) {
				MeshComp->SetMaterial(0, NewMaterial);
			}
		}

		if (Color == 2) {
			UMaterial* NewMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), NULL, TEXT("Material'/Game/StarterContent/Materials/azul.azul'")));
			if (NewMaterial != nullptr) {
				MeshComp->SetMaterial(0, NewMaterial);
			}
		}

		if (Color == 3) {
			UMaterial* NewMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), NULL, TEXT("Material'/Game/StarterContent/Materials/verde.verde'")));
			if (NewMaterial != nullptr) {
				MeshComp->SetMaterial(0, NewMaterial);
			}
		}

		if (Color == 4) {
			UMaterial* NewMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), NULL, TEXT("Material'/Game/StarterContent/Materials/Preto.Preto'")));
			if (NewMaterial != nullptr) {
				MeshComp->SetMaterial(0, NewMaterial);
			}
			Color = 0;
		}
			
	}
}

