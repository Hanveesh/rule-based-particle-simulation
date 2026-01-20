#include <iostream>
#include <optional>
#include <SFML/Graphics.hpp>

using namespace sf::Literals;

int main()
{

    sf::Window window(sf::VideoMode({400,400}), "First Window",sf::Style::Default,sf::State::Windowed);
    window.setPosition({0,0});
    
    sf::Vector2u size = window.getSize();

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while(const std::optional<sf::Event> event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
            }
            
            if(const auto* resized = event->getIf<sf::Event::Resized>()){
                std::cout<<"x: "<<resized->size.x<<std::endl;
                std::cout<<"y: "<<resized->size.y<<std::endl;
            }

            if(event->is<sf::Event::FocusLost>()){
                std::cout<<"Went out of window"<<std::endl;
            }

            if(event->is<sf::Event::FocusGained>()){
                std::cout<<"Came back into the window"<<std::endl;
            }

            if(const auto* MouseScrolled = event->getIf<sf::Event::MouseWheelScrolled>()){
                std::cout<<"Wheel Movement"<<MouseScrolled->delta<<std::endl;
            }

            if(const auto* MousePressed = event->getIf<sf::Event::MouseButtonPressed>()){
                if(MousePressed->button == sf::Mouse::Button::Right){
                    std::cout<<"Pressed right button"<<std::endl;
                }
                else if(MousePressed->button == sf::Mouse::Button::Left){
                    std::cout<<"Pressed left button"<<std::endl;
                }
            }

            // if(const auto* mousMoved = event->getIf<sf::Event::MouseMoved>()){
            //     std::cout<<"Mouse moved to "<< mousMoved->position.x<< " On x";
            //     std::cout<<" and Mouse moved to "<< mousMoved->position.y<< " On y" <<std::endl;
            // }
            // stopped this function because its giving too many outputs to keep track of 

            if(event->is<sf::Event::MouseEntered>()){
                std::cout<<"Mouse entered the WINDOW!!"<<std::endl;
            }

            if(event->is<sf::Event::MouseLeft>()){
                std::cout<<"Mouse LEFT the WINDOW!!!"<<std::endl;
            }
        }
    }


    
    return 0;
}
