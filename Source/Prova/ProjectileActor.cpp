// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "ProjectileActor.h"
#include "MyCharacter.h"



// Sets default values
AProjectileActor::AProjectileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	
	Root->InitSphereRadius(15.0f);
	Root->OnComponentBeginOverlap.AddDynamic(this, &AProjectileActor::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("BlockAll");
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}
	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(0.3f, 0.3f, 0.3f));
	MeshComp->AttachTo(RootComponent);

	Particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));

	//Particle->bAutoActivate = true;
	static ConstructorHelpers::FObjectFinder<UParticleSystem>ParticleSystem(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit'"));
	if (ParticleSystem.Succeeded()) {
		Particle->SetTemplate(ParticleSystem.Object);
	}
	Particle->SetupAttachment(RootComponent);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->UpdatedComponent = Root;
	ProjectileMovement->InitialSpeed = 3000.0f;
	ProjectileMovement->MaxSpeed = 3000.0f;
	InitialLifeSpan = 5.0f;


}

// Called when the game starts or when spawned
void AProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AProjectileActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && (OtherActor->IsA(AMyCharacter::StaticClass()))) {

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetLife(MyCharacter->GetLife() - 1);
		MyCharacter->OnDeath();

	}
}