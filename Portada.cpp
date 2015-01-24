#include "Portada.hpp"


    Portada::Portada() {
        open = true;
    }
    
    Portada::~Portada(){}
    
    void Portada::display(sf::RenderWindow* window){
        while(open){
            
            sf::Event event;
            while (window->pollEvent(event)) {
                switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) window->close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        open = false;
                    }
                default:
                    break;
                }
            }

            t.loadFromFile("res/Portada.png");
            s.setTexture(t);
            s.scale(window->getSize().x/s.getGlobalBounds().width,window->getSize().y/s.getGlobalBounds().height);

            window->draw(s);

            window->display();
                
        }
        
    }
