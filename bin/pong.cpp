/**
 * @file pong.cpp
 * Retro game Pong remaster in SFML
 *
 * @author Christopher Short
 * @date 2018.09.17
 *
 */

#include <SFML/Graphics.hpp>
#include "../src/computerview.h"
#include "../src/humanview.h"
#include "../src/logic.h"


/**
* If a key is pressed that is used to controler the game, this
* function captures the key press
*/
int Check4KeyPress()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        return 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        return 2;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        return 3;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
    {
        return 4;
    }
    return 0;
}


/**
* Contains main game loop
*/
int main(int argc, char** argv)
{
    // creates main window
    sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong - SFML");

    // creates logic and view componments
    computerview comp_view;
    humanview human_view(App);
    logic game_logic;

    // Used to adjust speed of the game based on speed of computer
    sf::Time LastUpdate = sf::Time::Zero;
    sf::Clock GameClock;

    // Stores the captured keypress (if any)
    int keypressed;

    // start main loop
    while(App.isOpen())
    {
        // Calculates the speed of the game
        sf::Time deltaMs = GameClock.restart();
        LastUpdate += deltaMs;

        // Main game loop
        sf::Event Event;
        while(App.pollEvent(Event))
        {
            // Exit
            if(Event.type == sf::Event::Closed)
            App.close();
        }

        // Listens for significant key presses
        keypressed = Check4KeyPress();

        // Updates the game logic which updates the views
        game_logic.Update(deltaMs, App, comp_view, human_view, keypressed);
    }

        // Done.
        return 0;
}
