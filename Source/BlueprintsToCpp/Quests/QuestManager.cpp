// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"

// Sets default values
AQuestManager::AQuestManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

FQuestInfo AQuestManager::GetQuest(FName Name) const
{
	return QuestList[GetQuestIndex(Name)];
}

// Called when the game starts or when spawned
void AQuestManager::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AQuestManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuestManager::CompleteQuest_Implementation(FName QuestId, bool CompleteWholeQuest)
{
	int32 QuestIndex = GetQuestIndex(QuestId);
	FQuestInfo Quest = QuestList[QuestIndex];
	if(CompleteWholeQuest)
	{
		QuestList[QuestIndex].Progress = Quest.ProgressTotal;
	}
	else
	{
		QuestList[QuestIndex].Progress = FMath::Min(Quest.Progress + 1, Quest.ProgressTotal);
	}

	CompletedQuest.Broadcast(QuestIndex);
}



