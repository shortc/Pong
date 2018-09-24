#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class paddle : public sf::RectangleShape
{
public:
    paddle(int);
    ~paddle();

    void LeftReset();
    void RightReset();
    void MoveUp(sf::Time&);
    void MoveDown(sf::Time&);
private:
    float speed;
};
#endif
