#ifndef COMPUTERVIEW_H
#define COMPUTERVIEW_H

#include "ball.h"
#include "paddle.h"

class computerview
{
public:
    computerview();

    void Update(sf::RenderWindow& App, ball* GameBall,
        paddle* RightPlayer, sf::Time& deltaMs);
};
#endif
