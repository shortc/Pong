#include <SFML/Graphics.hpp>
#include "humanview.h"

humanview::humanview(sf::RenderWindow& App)
{
    app_window = &App;

    // Create a graphical text to display
    font.loadFromFile("../src/fonts/Hack.ttf");

    // Initializes the non-moving objects
    LeftScore = new sf::Text();
    RightScore = new sf::Text();
    Restart = new sf::Text();
    Winner = new sf::Text();
    ExitInstructs = new sf::Text();
    RestartInstructs = new sf::Text();

    LeftScore->setString("00");
    RightScore->setString("00");
    Restart->setString("PONG");
    ExitInstructs->setString("Press Esc to EXIT");
    RestartInstructs->setString("Press F1 to RESTART");

    LeftScore->setFont(font);
    RightScore->setFont(font);
    Restart->setFont(font);
    Winner->setFont(font);
    ExitInstructs->setFont(font);
    RestartInstructs->setFont(font);

    LeftScore->setCharacterSize(20);
    RightScore->setCharacterSize(20);
    Restart->setCharacterSize(20);
    Winner->setCharacterSize(100);
    ExitInstructs->setCharacterSize(20);
    RestartInstructs->setCharacterSize(20);

    LeftScore->setPosition(sf::Vector2f(10, 10));
    RightScore->setPosition(sf::Vector2f(app_window->getSize().x - 40, 10));
    Restart->setPosition(app_window->getSize().x / 2 - 40, 10);
    Winner->setPosition(200, 200);
    ExitInstructs->setPosition(275, app_window->getSize().y - 30);
    RestartInstructs->setPosition(275, app_window->getSize().y - 50);

    Winner->setFillColor(sf::Color::Red);
}


/**
* Updates the View for the human player
*/
void humanview::Update(sf::RenderWindow& App, ball** GameBall, paddle** RightPlayer,
    paddle** LeftPlayer, std::string& RightScoreStr, std::string& LeftScoreStr, int GameWinner)
{

    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

    // When a player wins the games notifies who won
    if(GameWinner == 1)
    {
        Winner->setString("PLAYER 1\n   WINS!");
        App.draw(*Winner);
    }
    if(GameWinner == 2)
    {
        Winner->setString("PLAYER 2\n   WINS!");
        App.draw(*Winner);
    }

    // The score of the game is passed in from the game logic
    LeftScore->setString(LeftScoreStr);
    RightScore->setString(RightScoreStr);

    // Draws the game
    App.draw(*Restart);
    App.draw(*RightScore);
    App.draw(*LeftScore);
    App.draw(*ExitInstructs);
    App.draw(*RestartInstructs);
    App.draw(**LeftPlayer);
    App.draw(**RightPlayer);
    App.draw(**GameBall);

    // displays
    App.display();
}
