// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPowerUp.generated.h"

UCLASS()
class COOPGAME_API ASPowerUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASPowerUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "PowerUps")
	float PowerupInterval;

	UPROPERTY(EditDefaultsOnly, Category = "PowerUps")
	int32 TotalNbrOfTicks;

	FTimerHandle TimerHandle_PowerUpTick;

	int32 TicksProcessed;

	UFUNCTION()
	void OnTickPowerup();

public:	
	
	void ActivatePowerUp();

	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUps")
	void OnPowerUpTicked();

	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUps")
	void OnExpired();

	UFUNCTION(BlueprintImplementableEvent, Category = "PowerUps")
	void OnActivated();
};
