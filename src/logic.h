#ifndef LOGIC_H
#define LOGIC_H

#include "paddle.h"
#include "ball.h"
#include "computerview.h"
#include "humanview.h"
#include <string>

class logic
{
public:

    int LeftScore;
    int RightScore;
    int GameWinner;
    std::string LeftScoreStr;
    std::string RightScoreStr;

    ball* GameBall;
    paddle* RightPlayer;
    paddle* LeftPlayer;

    logic();
    ~logic();
    void Restart();
    void Check4Winner();
    void Check4KeyPress(int keypressed, sf::Time& deltaMs, sf::RenderWindow& App);
    void Update(sf::Time& deltaMs, sf::RenderWindow& App, computerview& comp_view,
        humanview& human_view, int keypressed);
};
#endif
