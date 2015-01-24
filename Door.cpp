#include "Door.hpp"
#include "Resources.hpp"

Door::Door() {
    down = false;
    up = false;
}


Door::Door(GameManager *gm) :
    Collisionable(gm, &Resources::doorTexture, Resources::doorTexture.getSize().x/4, Resources::doorTexture.getSize().y/4, 4, 4) {
    sprite.setPosition(0,0);
        down = false;
        up = false;
}

Door::Door(GameManager *gm, float px, float py) 
    : Collisionable(gm, &Resources::doorTexture, Resources::doorTexture.getSize().x/4, Resources::doorTexture.getSize().y/4, 4, 4) {
    sprite.setPosition(px,py);
        down = false;
        up = false;
}

Door::Door(GameManager *gm, float px, float py, float sx, float sy) 
    : Collisionable(gm, &Resources::doorTexture, Resources::doorTexture.getSize().x, Resources::doorTexture.getSize().y, px, py) {
    sprite.setPosition(px,py);
    sprite.setScale(sx/sprite.getGlobalBounds().width, sy/sprite.getGlobalBounds().height);
        down = false;
        up = false;
}

Door::~Door() {
    
}


void Door::draw(sf::RenderWindow* render) {
    render->draw(sprite);
}


void Door::moveDown(bool b) {
    down = b;
}

void Door::moveUp(bool b) {
    up = b;
}


void Door::update(float deltaTime) {
    if(down){ 
        sprite.setPosition(sprite.getPosition().x,sprite.getPosition().y+sprite.getGlobalBounds().height);
        down = false;
    }
    if(up){ 
        sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y-sprite.getGlobalBounds().height);
        up = false;
    }
}

