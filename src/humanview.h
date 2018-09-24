#ifndef HUMANVIEW_H
#define HUMANVIEW_H

//#include <SFML/Graphics.hpp>
#include "paddle.h"
#include "ball.h"

class humanview
{
public:

    // sf::RectangleShape* LeftPlayer;
    // sf::RectangleShape* RightPlayer;
    ball* GameBall;
    paddle* RightPlayer;
    paddle* LeftPlayer;
    sf::Font font;
    sf::Text* LeftScore;
    sf::Text* RightScore;
    sf::Text* Restart;

    sf::RenderWindow* app_window;

    humanview(sf::RenderWindow& App);
    ~humanview();

    void Update(sf::RenderWindow& App);
};
#endif
