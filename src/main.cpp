#include <iostream>
#include <optional>
#include <SFML/Graphics.hpp>

enum directions {down , right , up, left};

int main(){
    unsigned int width = 800;
    unsigned int height = 800;
    sf::RenderWindow window(sf::VideoMode({width,height}), "MyWindow");

    sf::Texture texture;

    if(!texture.loadFromFile("Sprites/ExampleSprite.png")){
        std::cerr<<"ERROR : FAILED TO LOAD TEXTURE::Sprites/ExampleSprite.png"<<std::endl;
        return -1;
    }
    
    sf::Sprite sprite(texture);

    sf::IntRect dir[4];
    
    for(int i = 0;i < 4;++i){

        dir[i] =  sf::IntRect({{32*i,0},{32,32}});
        
    }

    sprite.setTextureRect(dir[down]);
    sprite.setOrigin({16,16});
    sprite.setPosition({width/2.0f,height/2.0f});

    window.setFramerateLimit(60);

    while(window.isOpen()){



        while (const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
            }


        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)){
            sprite.move({0.0f,1.0f});
            sprite.setTextureRect(dir[down]);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)){
            sprite.move({0.0f,-1.0f});
            sprite.setTextureRect(dir[up]);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)){
            sprite.move({-1.0f,0.0f});
            sprite.setTextureRect(dir[left]);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)){
            sprite.move({1.0f,0.0f});
            sprite.setTextureRect(dir[right]);
        }

        window.clear();   

        window.draw(sprite);

        window.display();


    }

    return 0;
}



