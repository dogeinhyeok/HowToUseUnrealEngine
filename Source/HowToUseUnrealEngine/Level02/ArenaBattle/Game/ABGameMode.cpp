#include "ABGameMode.h"
#include "Player/ABPlayerController.h"


AABGameMode::AABGameMode()
{
    static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (ThirdPersonClassRef.Class)
    {
        DefaultPawnClass = ThirdPersonClassRef.Class;
    }

    PlayerControllerClass = AABPlayerController::StaticClass();
}