// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "ProvaGameMode.h"
#include "MyHUD.h"

AProvaGameMode::AProvaGameMode() {
	HUDClass = AMyHUD::StaticClass();
	UE_LOG(LogTemp, Warning, TEXT("qualquier coisa"));

}





