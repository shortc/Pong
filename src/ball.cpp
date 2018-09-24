#include "ball.h"

ball::ball() : sf::CircleShape()
{
    this->velocity.x = 300.0f;
    this->velocity.y = 300.0f;
    this->setRadius(5);
    this->setFillColor(sf::Color(250, 250, 250));
    this->setPosition(400, 300);
    this->setOrigin(this->getLocalBounds().width/2.0f,
        this->getLocalBounds().height/2.0f);
    this->RandVelocity();

}

ball::~ball()
{

}


/**
* Randomizes the velocity of the ball, called when the game is restarted or
* when a player scores. Adds randomness
*/
void ball::RandVelocity()
{
    // Ensures velocity in X dir is always abd(max)
    this->velocity.x = 300.0f;

    //Decides whether X velocity is pos or neg
    int randX = rand() % 2;
    // Descides the Y velocity [Range(-300, 300)]
    int randY = (rand() % 600) - 300;

    if (randX == 1)
        this->velocity.x *= -1.0f;

    this->velocity.y = (float) randY;
}


// Flips the velocity of the ball's velocity in the Y dir
void ball::ChangeDirY()
{
    this->velocity.y *= -1.0f;
}


/**
* Flips the velocity of the ball's velocity in the X dir
*/
void ball::ChangeDirX()
{
    this->velocity.x *= -1.0f;
}


/**
* Sets the ball's X velocity
*/
void ball::SetVelocityX(float NewX)
{
    this->velocity.x = NewX;
}


/**
* Sets the ball's Y velocity
*/
void ball::SetVelocityY(float NewY)
{
    this->velocity.y = NewY;
}


/**
* Returns the ball's Y velocity
*/
float ball::GetVelocityY()
{
    return this->velocity.y;
}


/**
* Returns the ball's X velocity
*/
float ball::GetVelocityX()
{
    return this->velocity.x;
}


/**
* Resets ball back to the middle of the screen. Called after a playe scores or
* when game is restarted
*/
void ball::Reset()
{
    this->setPosition(400, 300);
    this->RandVelocity();
}


/**
* Resets ball and stops it from moving. Called when a player wins
*/
void ball::GameOver()
{
    this->Reset();
    this->velocity.x = 0;
    this->velocity.y = 0;
}
