#include <SFML/Graphics.hpp>
#include "logic.h"


logic::logic()
{
    RightPlayer = new paddle(2);
    LeftPlayer = new paddle(1);
    GameBall = new ball();
    LeftScore = 0;
    RightScore = 0;
    GameWinner = 0;
    LeftScoreStr = "";
    RightScoreStr = "";
}

logic::~logic()
{

}


/**
* Updates the AI controlled paddle
*/
void logic::Restart()
{
    GameBall->Reset();
    GameBall->RandVelocity();
    RightPlayer->RightReset();
    LeftPlayer->LeftReset();
    LeftScore = 0;
    RightScore = 0;
    GameWinner = 0;
}


/**
* Checks whether a player has reached the required score of 11 to win the game
*/
void logic::Check4Winner()
{
    if(LeftScore == 11)
    {
        GameBall->GameOver();
        GameWinner = 1;
    }
    if(RightScore == 11)
    {
        GameBall->GameOver();
        GameWinner = 2;
    }
}


/**
* Takes the key press captured in the main loop and calls the correct action
*/
void logic::Check4KeyPress(int keypressed, sf::Time& deltaMs, sf::RenderWindow& App)
{
    switch(keypressed)
    {
        case 1:
            LeftPlayer->MoveUp(deltaMs);
            break;
        case 2:
            LeftPlayer->MoveDown(deltaMs);
            break;
        case 3:
            App.close();
            break;
        case 4:
            Restart();
            break;
    }
}


/**
* The main game logic. Called each cycle of the main game loop
*/
void logic::Update(sf::Time& deltaMs, sf::RenderWindow& App, computerview& comp_view,
    humanview& human_view, int keypressed)
{
    //Used to store the int value of each player's score
    LeftScoreStr = "";
    RightScoreStr = "";

    // Used to apply randomness to the reflection of the ball
    float randNum = (rand() % 100) - 50;

    // Finds the location of the sides of the paddle of the ball
    float left = GameBall->getPosition().x - GameBall->getOrigin().x;
    float right = GameBall->getPosition().x + GameBall->getOrigin().x;
    float top = GameBall->getPosition().y - GameBall->getOrigin().y;
    float bottom = GameBall->getPosition().y + GameBall->getOrigin().y;
    float top_pad_right = RightPlayer->getGlobalBounds().top;
    float top_pad_left = LeftPlayer->getGlobalBounds().top;
    float bottom_pad_right = RightPlayer->getGlobalBounds().top +
        RightPlayer->getGlobalBounds().height;
    float bottom_pad_left = LeftPlayer->getGlobalBounds().top +
        LeftPlayer->getGlobalBounds().height;
    float right_pad = LeftPlayer->getGlobalBounds().left +
        LeftPlayer->getGlobalBounds().width;

    // Checks to see if a player has won each game cycle
    Check4Winner();
    // Checks to see if a key press has been captured
    Check4KeyPress(keypressed, deltaMs, App);

    // If the ball has hit the left side of the screen the ball is reset and
    // a point is given to the opposite player
    if (left <= 0 && GameBall->GetVelocityX() < 0)
    {
        GameBall->Reset();
        RightScore++;
        //this->sound.play();
    }

    // If the ball has hit the right side of the screen the ball is reset and
    // a point is given to the opposite player
    if (right >= 800 && GameBall->GetVelocityX() > 0)
    {
        GameBall->Reset();
        LeftScore++;
        //this->sound.play();

    }

    // If the ball has hit the top or the bottom of the screen it is reflected
    if ((top <= 0 && GameBall->GetVelocityY() < 0) ||
        (bottom >= 600 && GameBall->GetVelocityY() > 0))
    {
        GameBall->ChangeDirY();
        GameBall->SetVelocityX(GameBall->GetVelocityX() + randNum);
        //this->sound.play();
    }

    // If the ball has hit the right player's paddle ball is reflected
    if (GameBall->getPosition().y <= bottom_pad_right &&
        GameBall->getPosition().y >= top_pad_right &&
        GameBall->getPosition().x >= RightPlayer->getGlobalBounds().left)
    {
		GameBall->ChangeDirX();
        GameBall->SetVelocityY(GameBall->GetVelocityY() + randNum);
    }

    // If the ball has hit the left player's paddle ball is reflected
    if (GameBall->getPosition().y <= bottom_pad_left &&
        GameBall->getPosition().y >= top_pad_left &&
        GameBall->getPosition().x <= right_pad)
    {
		GameBall->ChangeDirX();
        GameBall->SetVelocityY(GameBall->GetVelocityY() + (2 * randNum));
    }

    // Controls the ball's constant motion
    GameBall->move(deltaMs.asSeconds() * GameBall->GetVelocityX(),
        deltaMs.asSeconds() * GameBall->GetVelocityY());

    // Game score is converted to string so it can be displayed by the game view
    LeftScoreStr = std::to_string(LeftScore);
    RightScoreStr = std::to_string(RightScore);

    // Views of the human and AI are updated
    human_view.Update(App, &GameBall, &RightPlayer,
        &LeftPlayer, RightScoreStr, LeftScoreStr, GameWinner);
    comp_view.Update(App, GameBall, RightPlayer, deltaMs);
}
