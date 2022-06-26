// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Food.generated.h"


class USoundCue;

UENUM(BlueprintType)
enum class EFoodieType : uint8
{
	Regular,
	PowerUp

};

//delegator
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFoodieEatenEvent, EFoodieType, FoodieType);



UCLASS()
class PACMAN2_API AFood : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFood();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Consume();

	UPROPERTY(EditAnywhere)
		EFoodieType FoodieType = EFoodieType::Regular;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FFoodieEatenEvent FoodieEatenEvent;

private:
	UPROPERTY(EditAnywhere)
		USoundCue* ConsumptionSound;
};
