#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class ball : public sf::CircleShape
{
public:
    ball();
    ~ball();

    void RandVelocity();
    void ChangeDirY();
    void ChangeDirX();
    void SetVelocityX(float NewX);
    void SetVelocityY(float NewX);
    float GetVelocityY();
    float GetVelocityX();
    void Reset();
    void GameOver();
private:
    sf::Vector2f velocity;
};
#endif
