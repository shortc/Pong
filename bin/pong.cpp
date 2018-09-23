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

int main(int argc, char** argv)
{
    // create main window
    sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong - SFML");

    computerview comp_view;
    humanview human_view;
    logic logic;

    sf::Clock clock;

    // start main loop
    while(App.isOpen())
    {

        // process events
        sf::Event Event;
        while(App.pollEvent(Event))
        {
            // Exit
            if(Event.type == sf::Event::Closed)
            App.close();
        }



        logic.Update();
        human_view.Update(App);

    }

        // Done.
        return 0;
}
