#include "SpiderManCharacter.h"

#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"

ASpiderManCharacter::ASpiderManCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Bare-bones movement foundation.
    // Unreal's CharacterMovementComponent handles gravity,
    // walking, falling, collision, and basic jumping.
    GetCharacterMovement()->GravityScale = 1.0f;
    GetCharacterMovement()->MaxWalkSpeed = 600.0f;
    GetCharacterMovement()->JumpZVelocity = 500.0f;
    GetCharacterMovement()->AirControl = 0.35f;
}

void ASpiderManCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ASpiderManCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ASpiderManCharacter::MoveForward(float Value)
{
    if (Controller && Value != 0.0f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void ASpiderManCharacter::MoveRight(float Value)
{
    if (Controller && Value != 0.0f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void ASpiderManCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    check(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASpiderManCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASpiderManCharacter::MoveRight);
}
