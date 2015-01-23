#include "GameManager.hpp"

GameManager::GameManager(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style) {
}

GameManager::~GameManager() {}

void GameManager::update(float deltaTime) {
    player.update(deltaTime);
}

void GameManager::draw() {
    player.draw();
}

void GameManager::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) window.close();
            break;
        case sf::Event::KeyReleased:
            break;
        default:
            break;
        }
    }
}

sf::RenderTexture *GameManager::getRenderTexture() {
   return &renderText;
}

