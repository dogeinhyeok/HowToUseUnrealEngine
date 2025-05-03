#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "ABCharacterBase.h"
#include "InputActionValue.h"
#include "ABCharacterPlayer.generated.h"


UCLASS()
class HOWTOUSEUNREALENGINE_API AABCharacterPlayer : public AABCharacterBase
{
	GENERATED_BODY()

public:
	AABCharacterPlayer();

protected:
	virtual void BeginPlay() override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

// Camera
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;

// Input
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> LookAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};