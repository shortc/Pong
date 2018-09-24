#ifndef HUMANVIEW_H
#define HUMANVIEW_H

//#include <SFML/Graphics.hpp>
#include "paddle.h"
#include "ball.h"
#include <string>

class humanview
{
public:

    sf::Font font;
    sf::Text* LeftScore;
    sf::Text* RightScore;
    sf::Text* Restart;
    sf::Text* Winner;
    sf::Text* ExitInstructs;
    sf::Text* RestartInstructs;

    sf::RenderWindow* app_window;

    humanview(sf::RenderWindow& App);
    
    void Update(sf::RenderWindow& App, ball** GameBall, paddle** RightPlayer,
        paddle** LeftPlayer, std::string& RightScoreStr, std::string& LeftScoreStr, int GameWinner);
};
#endif
