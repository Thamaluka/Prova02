// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class PROVA_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	FORCEINLINE bool IsOpen()const { return Open; }
	FORCEINLINE void AMyCharacter::SetOpen(bool NewOpen) { Open = NewOpen; }


	void MoveForward(float Value);
	void MoveRight(float Value);
	void StartRun();
	void StopRun();

	void SetLife(int NewLife);
	int GetLife();

	void OnDeath();
	void SetColeta(int NewColeta);
	int GetColeta();

	void SetOpenDoor(int NewDoor);
	int GetOpenDoor();

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		UCameraComponent* PlayerCamera;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere)

		int Life = 3;
		int Coleta=0;
		int OpenDoor = 0;


		int Vermelho = 1;
		int Azul = 1;
		int Verde = 1;
		int Preto = 1;

		bool Open;

		UFUNCTION()
			void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

		UFUNCTION()
			void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult &Hit);
		
	
};
