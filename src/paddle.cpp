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

void paddle::MoveUp(sf::Time& delta)
{
    float top = this->getGlobalBounds().top;

    if(top > 0)
        this->move(0, -delta.asSeconds() * speed);
}

void paddle::MoveDown(sf::Time& delta)
{
	float bottom = this->getGlobalBounds().top + this->getGlobalBounds().height;

    if (bottom < 600)
        this->move(0, delta.asSeconds() * speed);
}
