#include "ABGameMode.h"
#include "Player/ABPlayerController.h"
#include "Character/ABCharacterPlayer.h"


AABGameMode::AABGameMode()
{
    DefaultPawnClass = AABCharacterPlayer::StaticClass();
    PlayerControllerClass = AABPlayerController::StaticClass();
}