#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class ball : public sf::CircleShape
{
public:
    ball();
    ~ball();

    void ChangeDirecton();
    void Reset();
private:
    sf::Vector2f speed;
};
#endif
