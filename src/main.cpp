#include <iostream>
#include <optional>
#include <SFML/Graphics.hpp>

enum directions {down , right , up, left};

int main(){
    unsigned int width = 800;
    unsigned int height = 800;
    sf::RenderWindow window(sf::VideoMode({width,height}), "MyWindow");

    sf::VertexArray triag(sf::PrimitiveType::Triangles,3);

    triag[0].position = sf::Vector2f({0.0f,height/1.0f});
    triag[1].position = sf::Vector2f({width/2.0f,height/2.0f});
    triag[2].position = sf::Vector2f({width/1.0f,height/1.0f});
    
    triag[0].color = sf::Color::Green;
    triag[1].color = sf::Color::Black;
    triag[2].color = sf::Color::Blue;

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

        window.clear();   

        window.draw(triag);

        window.display();


    }

    return 0;
}