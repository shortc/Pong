#ifndef HUMANVIEW_H
#define HUMANVIEW_H

class humanview
{
public:

    sf::RectangleShape* LeftPlayer;
    sf::RectangleShape* RightPlayer;
    sf::CircleShape* ball;

    humanview();
    ~humanview();

    void Update(sf::RenderWindow& App);
};
#endif
