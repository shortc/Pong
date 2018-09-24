/**
 * @file pong.cpp
 * Description
 *
 * @author Christopher Short
 * @date 2018.09.17
 *
 */

#include <SFML/Graphics.hpp>
#include "../src/computerview.h"
#include "../src/humanview.h"
#include "../src/logic.h"


void IsKeyPressed()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        // paddle move up
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        // paddle move down
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        // quit...
    }
}

int main(int argc, char** argv)
{
    // create main window
    sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong - SFML");

    computerview comp_view;
    humanview human_view(App);
    logic game_logic;

    // RightPlayer = new paddle(2);
    // LeftPlayer = new paddle(1);
    // GameBall = new ball();

    sf::Time deltaMs;
    sf::Clock clock;

    // start main loop
    while(App.isOpen())
    {
        deltaMs = clock.getElapsedTime();

        // process events
        sf::Event Event;
        while(App.pollEvent(Event))
        {
            // Exit
            if(Event.type == sf::Event::Closed)
            App.close();
        }
        IsKeyPressed();

        game_logic.Update(deltaMs);
        human_view.Update(App);
        comp_view.Update();

    }

        // Done.
        return 0;
}
