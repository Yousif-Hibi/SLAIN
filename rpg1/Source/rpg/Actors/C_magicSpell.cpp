#include "C_magicSpell.h"
#include <Components/SphereComponent.h>
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "rpg/Component/C_CollisionCombonent.h"
#include "C_BaseWeapon.h"
#include <rpg/SoulsLikeCharacter.h>
#include <Kismet/GameplayStatics.h>
#include "Engine/EngineTypes.h"
#include "rpg/Component/C_StatsComponent.h"
#include "rpg/AI/C_MasterAI.h"

// Sets default values
AC_magicSpell::AC_magicSpell()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	SetRootComponent(Sphere);

	Particales = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particales"));
	Particales->SetupAttachment(Sphere);
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	ProjectileMovement->UpdatedComponent = Sphere;
	ProjectileMovement->InitialSpeed = 1000.f;
	ProjectileMovement->MaxSpeed = 1000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->ProjectileGravityScale = 0;
}

// Called when the game starts or when spawned
void AC_magicSpell::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentHit.AddDynamic(this, &AC_magicSpell::OnHit);
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AC_magicSpell::AttackDealy, 1.0f, false);

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),
		StartParticales,
		GetActorLocation(),
		GetActorRotation()
	);
}

// Called every frame
void AC_magicSpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TargetActor)
	{
		FVector Direction = (TargetActor->GetActorLocation() - GetActorLocation()).GetSafeNormal();
		FVector NewLocation = GetActorLocation() + Direction * ProjectileMovement->MaxSpeed * DeltaTime;
		SetActorLocation(NewLocation);
	}
}

void AC_magicSpell::SetSpellDameges(float spellDmg)
{
	Dameges = spellDmg;
}

void AC_magicSpell::OnHit(UPrimitiveComponent* hitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	auto spellCaster = GetOwner();
	if (spellCaster == nullptr) return;

	auto* AIspellCaster = Cast<AC_MasterAI>(spellCaster);

	if (!Hit.GetActor())
	{
		return;
	}

	if (auto* Character = Cast<ASoulsLikeCharacter>(Hit.GetActor()))
	{
		UGameplayStatics::ApplyPointDamage(OtherActor,
			Dameges,
			spellCaster->GetActorForwardVector(),
			Hit,
			spellCaster->GetInstigatorController(),
			spellCaster,
			nullptr
		);
		if (IsValid(this))
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),
				hitParticales,
				GetActorLocation()
			);

			this->Destroy();
		}
	}
	else if (auto* AICharacter = Cast<AC_MasterAI>(Hit.GetActor()))
	{
		float value = 1;
		value = Dameges * value;

		UE_LOG(LogTemp, Warning, TEXT("hitai %s"), *Hit.GetActor()->GetName());

		UGameplayStatics::ApplyPointDamage(Hit.GetActor(),
			Dameges,
			GetOwner()->GetActorForwardVector(),
			Hit,
			GetInstigatorController(),
			GetOwner(),
			nullptr
		);
		if (IsValid(this))
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),
				hitParticales,
				GetActorLocation()
			);

			this->Destroy();
		}
	}
}

void AC_magicSpell::AttackDealy()
{
	if (this)
	{
		this->Destroy();
	}
}

void AC_magicSpell::SetTargetActor(AActor* NewTarget)
{
	TargetActor = NewTarget;
}
