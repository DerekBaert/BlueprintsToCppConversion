// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestMarker.generated.h"

class UNiagaraComponent;

UCLASS()
class BLUEPRINTSTOCPP_API AQuestMarker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestMarker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UNiagaraComponent* NiagaraSystem;

};
