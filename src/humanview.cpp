#include <SFML/Graphics.hpp>
#include "humanview.h"
//#include "paddle.h"

humanview::humanview(sf::RenderWindow& App)
{

    //sf::RectangleShape LeftPlayer(sf::Vector2f(30, 200));
    //sf::RectangleShape RightPlayer(sf::Vector2f(30, 200));
    //sf::CircleShape ball(5);

    app_window = &App;

    RightPlayer = new paddle(2);
    LeftPlayer = new paddle(1);
    GameBall = new ball();

    // ball = new sf::CircleShape();
    // RightPlayer = new sf::RectangleShape();
    // LeftPlayer = new sf::RectangleShape();
    //
    // ball->setRadius(5);
    // RightPlayer->setSize(sf::Vector2f(30, 200));
    // LeftPlayer->setSize(sf::Vector2f(30, 200));
    //
    // RightPlayer->setFillColor(sf::Color(250, 250, 250));
    // LeftPlayer->setFillColor(sf::Color(250, 250, 250));
    // ball->setFillColor(sf::Color(250, 250, 250));
    //
    // ball->setPosition(400, 300);
    // LeftPlayer->setPosition(20, 200);
    // RightPlayer->setPosition(750, 200);

    // Create a graphical text to display
    font.loadFromFile("../src/fonts/Hack.ttf");
    LeftScore = new sf::Text();
    RightScore = new sf::Text();
    Restart = new sf::Text();
    LeftScore->setString("FIX");
    RightScore->setString("FIX");
    Restart->setString("RESTART");
    LeftScore->setFont(font);
    RightScore->setFont(font);
    Restart->setFont(font);
    LeftScore->setCharacterSize(20);
    RightScore->setCharacterSize(20);
    Restart->setCharacterSize(20);
    LeftScore->setPosition(sf::Vector2f(10, 10));
    RightScore->setPosition(sf::Vector2f(app_window->getSize().x - 40, 10));
    Restart->setPosition(app_window->getSize().x / 2 - 40, 10);
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
    App.draw(*Restart);
    App.draw(*RightScore);
    App.draw(*LeftScore);
    App.draw(*LeftPlayer);
    App.draw(*RightPlayer);
    App.draw(*GameBall);

    // display
    App.display();
}
