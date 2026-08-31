#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpiderManCharacter.generated.h"

UCLASS()
class SPIDERMANSIMULATOR_API ASpiderManCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ASpiderManCharacter();

protected:
    virtual void BeginPlay() override;

    void MoveForward(float Value);
    void MoveRight(float Value);

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(
        class UInputComponent* PlayerInputComponent
    ) override;
};
