#include <iostream>
#include <optional>
#include <SFML/Graphics.hpp>

using namespace sf::Literals;

int main(){
    unsigned int width = 400;
    unsigned int height = 500;
    sf::RenderWindow window(sf::VideoMode({width,height}), "MyWindow");

    window.setFramerateLimit(144);
    float radius = 50.0;
    sf::CircleShape circle(radius);
    circle.setOrigin(circle.getGeometricCenter());
    circle.setPosition({width / 4.0f , height/2.0f});
    circle.setFillColor(sf::Color::Green);
    circle.setOutlineThickness(6.5f);
    circle.setOutlineColor(sf::Color::Red);


    sf::RectangleShape rectangle({30.0f,70.0f});
    rectangle.setOrigin(rectangle.getSize() / 2.0f);
    rectangle.setPosition({width / 4.0f , height/2.0f});
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOutlineThickness(5.0f);
    rectangle.setOutlineColor(sf::Color::Green);



    int r = 0;
    int s = 2;

    circle.setPointCount(3);
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



        std::cout<<r<<std::endl;

        if(r == 0){
            std::cout<<circle.getPosition().x;
            if(circle.getPosition().x >= (width - radius)){
                s+=2;
                r = 1;
            }
            else{
                std::cout<<" moving Right";
                circle.rotate(sf::degrees(s));
                circle.move({1,0});
            }
        }

        if (r == 1){
            if(circle.getPosition().x <= (radius)){
                s+=2;
                r = 0;
            }
            else{
                std::cout<<" moving Left";
                circle.rotate(sf::degrees(-s));
                circle.move({-1,0});
            }            
        }

        circle.setFillColor(sf::Color::Green);
        rectangle.setFillColor(sf::Color::Red);

        if(circle.getGlobalBounds().findIntersection(rectangle.getGlobalBounds())){
            std::cout<<"Intersected";
            circle.setFillColor(sf::Color::White);
            rectangle.setFillColor(sf::Color::White);
        }


        window.clear();   

        window.draw(circle);window.draw(rectangle);
        window.display();


    }



    return 0;
}



