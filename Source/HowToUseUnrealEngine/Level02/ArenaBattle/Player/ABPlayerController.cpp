#include "ABPlayerController.h"


void AABPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    FInputModeGameOnly GameOnlyInputMode;
    SetInputMode(GameOnlyInputMode);
}