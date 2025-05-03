#include "ABCharacterPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


AABCharacterPlayer::AABCharacterPlayer()
{
	// Camera
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 400.0f;
    CameraBoom->bUsePawnControlRotation = true;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    // Input
    static ConstructorHelpers::FObjectFinder<UInputMappingContext> DefaultMappingContextRef(TEXT("/Game/ArenaBattle/Input/IMC_Default"));
    if (DefaultMappingContextRef.Succeeded())
    {
        DefaultMappingContext = DefaultMappingContextRef.Object;
    }

    static ConstructorHelpers::FObjectFinder<UInputAction> MoveActionRef(TEXT("/Game/ArenaBattle/Input/Actions/IA_Move"));
    if (MoveActionRef.Succeeded())
    {
        MoveAction = MoveActionRef.Object;
    }

    static ConstructorHelpers::FObjectFinder<UInputAction> LookActionRef(TEXT("/Game/ArenaBattle/Input/Actions/IA_Look"));  
    if (LookActionRef.Succeeded())
    {
        LookAction = LookActionRef.Object;
    }

    static ConstructorHelpers::FObjectFinder<UInputAction> JumpActionRef(TEXT("/Game/ArenaBattle/Input/Actions/IA_Jump"));
    if (JumpActionRef.Succeeded())
    {
        JumpAction = JumpActionRef.Object;
    }
}

void AABCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();

    APlayerController* PlayerController = Cast<APlayerController>(GetController());
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(DefaultMappingContext, 0);
    }
}

void AABCharacterPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

    EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
    EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::StopJumping);
    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::Move);
    EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AABCharacterPlayer::Look);
}

void AABCharacterPlayer::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

    const FRotator Rotation = Controller->GetControlRotation();
    const FRotator YawRotation(0, Rotation.Yaw, 0);

    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    AddMovementInput(ForwardDirection, MovementVector.X);
    AddMovementInput(RightDirection, MovementVector.Y);
}

void AABCharacterPlayer::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}