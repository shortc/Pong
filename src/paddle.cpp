#include "paddle.h"

paddle::paddle(int PadPosition) : sf::RectangleShape()
{
    this->speed = 300.0f;
    this->setSize(sf::Vector2f(30, 200));
    this->setFillColor(sf::Color(250, 250, 250));

    if(PadPosition == 1)
        this->setPosition(20, 200);
    else
        this->setPosition(750, 200);
}

paddle::~paddle()
{

}


/**
* Resets the left paddle to the starting position.
* Called when game is restarted
*/
void paddle::LeftReset()
{
    this->setPosition(20, 200);
}


/**
* Resets the right paddle to the starting position.
* Called when game is restarted
*/
void paddle::RightReset()
{
    this->setPosition(750, 200);
}


/**
* Moves paddle up
*/
void paddle::MoveUp(sf::Time& delta)
{
    // Finds the location of the top of the paddle
    float top = this->getGlobalBounds().top;

    // Stops any part of the paddle from moving out of bounds
    if(top > 0)
        this->move(0, -delta.asSeconds() * speed);
}


/**
* Moves paddle down
*/
void paddle::MoveDown(sf::Time& delta)
{
    // Finds the location of the bottom of the paddle
	float bottom = this->getGlobalBounds().top + this->getGlobalBounds().height;

    // Stops any part of the paddle from moving out of bounds
    if (bottom < 600)
        this->move(0, delta.asSeconds() * speed);
}
