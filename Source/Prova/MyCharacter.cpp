// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "MyCharacter.h"
#include "ChangeColorActor.h"
#include "Porta.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->bGenerateOverlapEvents = true;

	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AMyCharacter::OnOverlapEnd);
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AMyCharacter::OnHit);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->AttachTo(GetCapsuleComponent());


	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	PlayerCamera->AttachTo(CameraBoom);

	GetCharacterMovement()->MaxWalkSpeed = 800;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	Life = 3;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	InputComponent->BindAction("Run", IE_Pressed, this, &AMyCharacter::StartRun);
	InputComponent->BindAction("Run", IE_Released, this, &AMyCharacter::StopRun);

}

void AMyCharacter::MoveForward(float Value) {

	FVector Forward(1, 0, 0);
	AddMovementInput(Forward, Value);
}

void AMyCharacter::MoveRight(float Value) {
	FVector Right(0, 1, 0);
	AddMovementInput(Right, Value);
}

void AMyCharacter::StartRun() {
	GetCharacterMovement()->MaxWalkSpeed = 1000;
}

void AMyCharacter::StopRun() {
	GetCharacterMovement()->MaxWalkSpeed = 800;
}


void AMyCharacter::SetLife(int NewLife) {
	Life = NewLife;
}

int AMyCharacter::GetLife() {
	return Life;
}

void AMyCharacter::OnDeath() {
	FVector InitialLocation(-710.0f, 550.0f, 78.0f);
	if (Life <= 0) {
		Life = 3;
		SetActorLocation(InitialLocation);
	}
}

void AMyCharacter::SetColeta(int NewColeta) {
	Coleta = NewColeta;
}

int AMyCharacter::GetColeta() {
	return Coleta;
}

void AMyCharacter::SetOpenDoor(int NewDoor) {
	OpenDoor = NewDoor;
}

int AMyCharacter::GetOpenDoor() {
	return OpenDoor;

}



void AMyCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (OtherActor->IsA(AChangeColorActor::StaticClass()))) {

		AChangeColorActor* ColorActor = Cast<AChangeColorActor>(OtherActor);
		UE_LOG(LogTemp, Warning, TEXT("Vermelho  %d"),Vermelho);
		UE_LOG(LogTemp, Warning, TEXT("Azul %d"), Azul);
		UE_LOG(LogTemp, Warning, TEXT("Verde %d"), Verde);

		if (ColorActor->GetColor() == 1) {
			Vermelho++;
			if (Vermelho == 5) {
				OpenDoor = 1;
			}
			if (Verde > 1) {
				Verde--;
			}
		}else

		if (ColorActor->GetColor() == 2) {
			Azul++;
			if (Azul == 5) {
				OpenDoor = 2;
			}
			if (Vermelho >1) {
				Vermelho--;
			}
		}else

		if (ColorActor->GetColor() == 3) {
			Verde++;
			if (Verde == 5) {
				OpenDoor = 3;
			}
		
			if (Azul > 1) {
				Azul--;
			}
		}
		else if(ColorActor->GetColor() == 4) {
			Vermelho = 1;
			Azul = 1;
			Verde = 1;
		}
	
	}
}

void AMyCharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult &Hit) {
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (OtherActor->IsA(APorta::StaticClass()))) {
		
		APorta* Porta = Cast<APorta>(OtherActor);

		Porta->DestroyDoor(OpenDoor);
		
	
	}
}