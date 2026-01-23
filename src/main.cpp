#include <iostream>
#include <optional>
#include <SFML/Graphics.hpp>

using namespace sf::Literals;

int main(){
    unsigned int width = 400;
    unsigned int height = 500;
    sf::RenderWindow window(sf::VideoMode({width,height}), "MyWindow");

    sf::ConvexShape convex;
    convex.setPointCount(6);
    
    convex.setPoint(0, {0.f, -50.f});
    convex.setPoint(1, {40.f, -20.f});
    convex.setPoint(2, {25.f, 40.f});
    convex.setPoint(3, {-25.f, 40.f});
    convex.setPoint(4, {-40.f, -20.f});
    convex.setPoint(5, {0.f, -50.f});

    convex.setOrigin(convex.getGeometricCenter());
    convex.setFillColor(sf::Color::Green);
    convex.setPosition({width/2.0f,height/2.0f});
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

        window.draw(convex);

        window.display();


    }



    return 0;
}



