// Fill out your copyright notice in the Description page of Project Settings.


#include "C_BaseMagicWeapon.h"
#include "rpg/Component/C_CollisionCombonent.h"
#include "C_magicSpell.h"
#include "Particles/ParticleSystemComponent.h"
#include "rpg/SoulsLikeCharacter.h"
#include "rpg/AI/C_MasterAI.h"
#include <Kismet/GameplayStatics.h>

AC_BaseMagicWeapon::AC_BaseMagicWeapon()
{

	//spell= CreateDefaultSubobject<AC_magicSpell>(TEXT("Collision"));
	ProjectileSpawn = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawn"));
	ProjectileSpawn->SetupAttachment(ItemStaticMesh);
	

	Particales = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particales"));
	Particales->SetupAttachment(ItemStaticMesh);
	

	ProjectialCollisionCombonent = CreateDefaultSubobject<UC_CollisionCombonent>(TEXT("LeftHandCollision"));
	ProjectialCollisionCombonent->FonHit.AddDynamic(this, &AC_BaseWeapon::OnHit);

	


}

void AC_BaseMagicWeapon::BeginPlay()
{
	Super::BeginPlay();
	Particales->SetVisibility(false);
	magicDameges = 20.f;
	
}
 


void AC_BaseMagicWeapon::ToggleCombat(bool bEnableCombate)
{
	AC_BaseWeapon::ToggleCombat(bEnableCombate);
	if (bEnableCombate) {
		Particales->SetVisibility(true);
	}
	else {
		Particales->SetVisibility(false);
	}
}

void AC_BaseMagicWeapon::fire()
{
	UE_LOG(LogTemp, Warning, TEXT("asdasdasdasda %f"), magicDameges);
	
	auto* MainCharacter = Cast<AC_MasterAI>(GetOwner());
	FVector  ProjectileSpawnLocation = ProjectileSpawn->GetComponentLocation();
	FRotator  rotator = MainCharacter->GetActorRotation();
	Spell = GetWorld()->SpawnActor<AC_magicSpell>(magicSpell, ProjectileSpawnLocation, rotator);
	Spell->SetOwner(MainCharacter);
	Spell->SetSpellDameges(magicDameges);
	Spell->SetTargetActor(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void AC_BaseMagicWeapon::MagicDamegeSet(float temp)
{
	
	
		magicDameges = temp;	
		UE_LOG(LogTemp, Warning, TEXT("asdasdasdasda %f"), magicDameges);
	
}
