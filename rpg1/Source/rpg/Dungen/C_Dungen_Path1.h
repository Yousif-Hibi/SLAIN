// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "C_room.h"
#include "C_Dungen_Path1.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API AC_Dungen_Path1 : public AC_room
{
	GENERATED_BODY()
public:
	AC_Dungen_Path1();


	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* WallLeft3;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* WallRight3;
	UPROPERTY(EditAnywhere)
	UArrowComponent* ArrowGenrate1;


	UPROPERTY(EditAnywhere)
	UArrowComponent* spawnPoint2;
	UPROPERTY(EditAnywhere)
	UArrowComponent* spawnPoint3;
	UPROPERTY(EditAnywhere)
	UArrowComponent* spawnPoint4;
	UPROPERTY(EditAnywhere)
	UArrowComponent* spawnPoint5;
	UPROPERTY(EditAnywhere)
	UArrowComponent* spawnPoint6;
	UPROPERTY(EditAnywhere)
	UArrowComponent* spawnPoint7;
	UPROPERTY(EditAnywhere)
	UArrowComponent* spawnPoint8;
	UPROPERTY(EditAnywhere)
	UArrowComponent* spawnPoint9;



	UPROPERTY(EditAnywhere)
	UArrowComponent* wallspawnPoint2;
	UPROPERTY(EditAnywhere)
	UArrowComponent* wallspawnPoint3;
	UPROPERTY(EditAnywhere)
	UArrowComponent* wallspawnPoint4;
	UPROPERTY(EditAnywhere)
	UArrowComponent* wallspawnPoint5;
	UPROPERTY(EditAnywhere)
	UArrowComponent* wallspawnPoint6;
	UPROPERTY(EditAnywhere)
	UArrowComponent* wallspawnPoint7;
	UPROPERTY(EditAnywhere)
	UArrowComponent* wallspawnPoint8;
};