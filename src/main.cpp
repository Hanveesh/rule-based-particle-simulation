#include <iostream>
#include <optional>
#include <vector>
#include <SFML/Graphics.hpp>

enum directions {down , right , up, left};

int main(){
    unsigned int width = 800;
    unsigned int height = 800;
    sf::RenderWindow window(sf::VideoMode({width,height}), "MyWindow");

    window.setFramerateLimit(120);
    int shapes = 0;
    std::vector<sf::RectangleShape> arr;

    sf::RectangleShape rectanlge({200,100});
    rectanlge.setOrigin(rectanlge.getGeometricCenter());
    rectanlge.setPosition({width/2.0f,height/2.0f});


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

            if(auto* Mouse = event->getIf<sf::Event::MouseButtonPressed>()){
                if(Mouse->button == sf::Mouse::Button::Left){

                    if(shapes < 10){
                        std::cout<<"Pressed M1"<<std::endl;
                        
                        sf::RectangleShape rt;

                        rt.setSize({200,100});
                        rt.setOrigin(rt.getGeometricCenter());
                        rt.setPosition(static_cast<sf::Vector2f>(Mouse->position));
                        rt.setFillColor(sf::Color::White);

                        arr.push_back(rt);

                        shapes++;                        
                    }

                }
            }

        }

        window.clear();   
        
        if( rectanlge.getPosition().y != height-50 ){

            rectanlge.move({0.0f,1.0f});

        }
        window.draw(rectanlge);

        for(int i = 0 ; i< shapes;i++){
            if(arr[i].getPosition().y != height-50){
            arr[i].move({0.0f,1.0f});
            }

            window.draw(arr[i]);
        }

        window.display();


    }

    return 0;
}