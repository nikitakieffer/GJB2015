#ifndef PLAYER_H
#define PLAYER_H


#include "utils.hpp"
#include "Collisionable.hpp"


class Player : public Collisionable {
private:
    sf::Vector2f lastGround;
    PState::level state;
    sf::Vector2u spriteSource;
    float scont;
    float* time_to_next_sprite;
    bool jumping;
    float jumpTimer;
    Dir::Direction lastDir;

    int *nSprites;
    bool pushing;

    void loadNewLevel(PState::level level);
    void animation(float deltaTime);
    void nextFrame();

public:
    Player();
    Player(GameManager *gm);
    Player(GameManager *gm, float px, float py);
    ~Player();
    void update(float deltaTime);
    void draw(sf::RenderWindow* window);
    void jump(bool jump);
    Dir::Direction getDirection();

};

#endif // PLAYER_H
