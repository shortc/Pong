#include <SFML/Graphics.hpp>
#include "humanview.h"
#include "paddle.h"

humanview::humanview()
{

    //sf::RectangleShape LeftPlayer(sf::Vector2f(30, 200));
    //sf::RectangleShape RightPlayer(sf::Vector2f(30, 200));
    //sf::CircleShape ball(5);

    ball = new sf::CircleShape();
    RightPlayer = new sf::RectangleShape();
    LeftPlayer = new sf::RectangleShape();

    ball->setRadius(5);
    RightPlayer->setSize(sf::Vector2f(30, 200));
    LeftPlayer->setSize(sf::Vector2f(30, 200));

    RightPlayer->setFillColor(sf::Color(250, 250, 250));
    LeftPlayer->setFillColor(sf::Color(250, 250, 250));
    ball->setFillColor(sf::Color(250, 250, 250));

    ball->setPosition(400, 300);
    LeftPlayer->setPosition(20, 200);
    RightPlayer->setPosition(750, 200);

    // Create a graphical text to display
    //sf::Font font;
    //font.loadFromFile("../src/fonts/Hack.ttf");
    //sf::Text text("PONG", font, 50);
}

humanview::~humanview()
{

}

void humanview::Update(sf::RenderWindow& App)
{
    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

    // Draw the string
    //App.draw(text);

    App.draw(*LeftPlayer);
    App.draw(*RightPlayer);
    App.draw(*ball);

    // display
    App.display();
}
