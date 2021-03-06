#pragma once

#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Engine/World.h"
#include "GameEventManager.generated.h"

class UGameEventContainer;
class UGameEventContainerObject;
class UGameEventObject;

UCLASS()
class CT_GAMEEVENTSYSTEM_API AGameEventManager : public AActor
{
	GENERATED_BODY()
	
public:	

	/************************************************************************/
	/* PROPERTIES                                                           */
	/************************************************************************/
		
	UPROPERTY(Category = "Game Event Manager", BlueprintReadWrite, EditDefaultsOnly, meta = (DisplayName = "Game Event Container"))
	UGameEventContainer* GameEventContainerBase;

	UPROPERTY(Category = "Game Event Manager", BlueprintReadWrite)
	UGameEventContainerObject* GameEventContainer;

	/************************************************************************/
	/* METHODS                                                              */
	/************************************************************************/

	// Sets default values for this actor's properties
	AGameEventManager();

protected:

	virtual void Init();

public: 

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Overridable function called whenever this actor is being removed from a level */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/**
	* Loop on each GameEvents in the container and check if the EventsTags is matching with the GameEvent
	*
	* @param FGameplayTagContainer EventsTags - EventTags matching to activate
	*
	* @return bool - true if some events has been activated, false otherwise
	*/
	UFUNCTION(Category = "Game Event Manager", BlueprintCallable)
	virtual bool TryActivateEvents(FGameplayTagContainer EventsTags);

	/**
	* Get GameEvent with the Id given
	*
	* @param FGuid Id
	*
	* @return UGameEvent* - Instance found or nullptr
	*/
	UFUNCTION(Category = "Game Event Manager", BlueprintCallable)
	virtual UGameEventObject* GetGameEventById(FGuid Id);

	/**
	* Add custom tag can be useful for system like quest
	* Example: if your UI need to have the active quest selected
	*
	* @param FGameplayTagContainer CustomTags
	*/
	UFUNCTION(Category = "Game Event Manager", BlueprintCallable)
	virtual void AddCustomTagsToEvent(FGameplayTagContainer CustomTags, UGameEventObject* GameEvent);

	/**
	* Remove custom tag
	*
	* @param FGameplayTagContainer CustomTags
	*/
	UFUNCTION(Category = "Game Event Manager", BlueprintCallable)
	virtual void RemoveCustomTagsToEvent(FGameplayTagContainer CustomTags, UGameEventObject* GameEvent);

};
