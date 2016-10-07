// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "MyHUD.h"
#include "Engine/Font.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.h"
#include "Coletaveis.h"


AMyHUD::AMyHUD() {
	static ConstructorHelpers::FObjectFinder<UFont>
		Font(TEXT("Font'/Engine/EngineFonts/TinyFont.TinyFont'"));

	if (Font.Succeeded()) {
		HUDFont = Font.Object;
	}


	static ConstructorHelpers::FObjectFinder<UTexture2D>
		Texture(TEXT("Texture2D'/Game/StarterContent/Textures/vidas.vidas'"));
	if (Texture.Succeeded()) {
		MyTexture = Texture.Object;
	}


}

void AMyHUD::DrawHUD() {
	Super::DrawHUD();
	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	AMyCharacter* MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));


	FString LifeString = FString::Printf(TEXT("Life: %d"), MyCharacter->GetLife());
	FString Coletaveis = FString::Printf(TEXT("Coletaveis: 3/ %d"), MyCharacter->GetColeta());
	FString Vitoria = FString::Printf(TEXT("Parabens, Voce Ganhou!!"));

	int LifeChar = MyCharacter->GetLife();

	if (LifeChar == 3) {
		DrawTextureSimple(MyTexture, 50, 50, 0.3f, false);
		DrawTextureSimple(MyTexture, 80, 50, 0.3f, false);
		DrawTextureSimple(MyTexture, 110, 50, 0.3f, false);
	}

	if (LifeChar == 2) {
		DrawTextureSimple(MyTexture, 50, 50, 0.3f, false);
		DrawTextureSimple(MyTexture, 80, 50, 0.3f, false);
	}

	if (LifeChar == 1) {
		DrawTextureSimple(MyTexture, 50, 50, 0.3f, false);
	}

	DrawText(Coletaveis, FColor::Black, 50, 100, HUDFont);

	if (MyCharacter->IsOpen()) {
		DrawText(Vitoria, FColor::Black, 400, 200, HUDFont);
	}
	
	



}


