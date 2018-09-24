#include "computerview.h"

computerview::computerview()
{

}


/**
* Updates the AI controlled paddle
*/
void computerview::Update(sf::RenderWindow& App, ball* GameBall,
    paddle* RightPlayer, sf::Time& deltaMs)
{
    // If the ball is below the paddle, the AI's paddle is moved down
    if(GameBall->getPosition().y > RightPlayer->getPosition().y + 100)
    {
        RightPlayer->MoveDown(deltaMs);
    }
    // If the ball is above the paddle, the AI's paddle is moved up
    if(GameBall->getPosition().y < RightPlayer->getPosition().y + 100)
    {
        RightPlayer->MoveUp(deltaMs);
    }
}
