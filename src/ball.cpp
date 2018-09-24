#include "ball.h"

ball::ball() : sf::CircleShape()
{
    this->speed.x = 300.0f;
    this->speed.y = 300.0f;
    this->setRadius(5);
    this->setFillColor(sf::Color(250, 250, 250));
    this->setPosition(400, 300);
    this->setOrigin(this->getLocalBounds().width/2.0f, this->getLocalBounds().height/2.0f);

}

ball::~ball()
{

}

void ball::ChangeDirecton()
{

}

void ball::Reset()
{
    this->setPosition(400, 300);
}
