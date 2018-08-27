// Fill out your copyright notice in the Description page of Project Settings.

#include "SPowerUp.h"


// Sets default values
ASPowerUp::ASPowerUp()
{
	PowerupInterval = 0.0f;
	TotalNbrOfTicks = 0;
}

// Called when the game starts or when spawned
void ASPowerUp::BeginPlay()
{
	Super::BeginPlay();

}

void ASPowerUp::OnTickPowerup()
{
	TicksProcessed++;

	OnPowerUpTicked();

	if (TicksProcessed >= TotalNbrOfTicks)
	{
		OnExpired();

		GetWorldTimerManager().ClearTimer(TimerHandle_PowerUpTick);
	}
}

void ASPowerUp::ActivatePowerUp()
{
	OnActivated();
	if (PowerupInterval > 0.0f)
	{
		GetWorldTimerManager().SetTimer(TimerHandle_PowerUpTick, this, &ASPowerUp::OnTickPowerup, PowerupInterval, true);
	}
	else
	{
		OnTickPowerup();
	}
}

void OnPowerUpTicked()
{

}

void OnExpired()
{

}

void OnActivated()
{

}