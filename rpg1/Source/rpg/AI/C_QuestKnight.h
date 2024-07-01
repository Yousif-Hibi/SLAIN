// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "C_MasterAI.h"
#include "C_QuestKnight.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API AC_QuestKnight : public AC_MasterAI, public IInteractive_CI
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AC_QuestKnight(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void TalkToNPC();
	void ShowWidget(FString str);

	UFUNCTION(BlueprintCallable)
	static FString ReadStringFromFile(FString FilePath,bool& bOutSuccess,FString& OutInfoMassage);

	UFUNCTION(BlueprintCallable)
	static void WriteStringToFile(FString FilePath,FString  String, bool& bOutSuccess, FString& OutInfoMassage);

	UFUNCTION(BlueprintCallable)
	FString RunPythonScript(FString ScriptPath, FString TextToSend);

	UFUNCTION(BlueprintCallable)
    void CreateQuestFile();
	UPROPERTY(EditAnywhere)
	int32 PartNumber= 1;
	UFUNCTION()
	void Teleport(FVector Location);
	UFUNCTION()
	void fileToRead();
private:
	UPROPERTY()
	TSubclassOf<UUserWidget> widget;

	UPROPERTY()
	UUserWidget* CurrentWidget;

	FTimerHandle WidgetTimerHandle;
	UPROPERTY()
	bool bAllowedTOTelleport=false;

	TArray<FString> Dialog;
	int32 DialogIndex = -1;

	void RemoveCurrentWidget();


};