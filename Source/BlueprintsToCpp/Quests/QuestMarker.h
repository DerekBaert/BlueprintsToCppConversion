// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestManager.h"
#include "QuestMarker.generated.h"

class UNiagaraComponent;

UCLASS()
class BLUEPRINTSTOCPP_API AQuestMarker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestMarker();

	UFUNCTION(BlueprintCallable)
	void RefreshVisibility();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	AQuestManager* GetQuestManager() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UNiagaraComponent* NiagaraSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName QuestName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 ShowAtProgress = 0;

};
