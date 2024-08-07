// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "rpg/Enums/E_CollisionPart.h"
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "CollisionTrace_ANS.generated.h"

/**
 * 
 */
UCLASS()
class  RPG_API UCollisionTrace_ANS : public UAnimNotifyState
{
	GENERATED_BODY()
public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)override;

	bool Received_NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) ;
	bool Received_NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) ;
public:
	UPROPERTY(EditAnywhere)
	TEnumAsByte< ECollisionPart> collisionPart;

};
