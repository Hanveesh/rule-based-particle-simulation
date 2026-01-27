#include <iostream>
#include <optional>
#include <vector>
#include <SFML/Graphics.hpp>

enum State {Empty = 0 , Filled = 1};

int main(){
    constexpr unsigned int width = 800;
    constexpr unsigned int height = 800;

    constexpr unsigned int cell_len = 4;

    constexpr unsigned int grid_s = 800/cell_len;

    std::vector<int> grid(grid_s*grid_s);
    unsigned int shapes = 0;

    sf::RenderWindow window(sf::VideoMode({width,height}), "MyWindow");

    window.setFramerateLimit(60);
    std::vector<sf::RectangleShape> arr;

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

                    std::cout<<"Pressed M1"<<std::endl;
                    
                    sf::RectangleShape rt;
                    rt.setSize({cell_len,cell_len});
                    rt.setOrigin(rt.getGeometricCenter());
                                            
                    sf::Vector2f MousePos = static_cast<sf::Vector2f>(Mouse->position);
                    float grid_x = static_cast<float>((static_cast<int>(MousePos.x) / cell_len));
                    float grid_y = static_cast<float>((static_cast<int>(MousePos.y) / cell_len));

                    rt.setPosition({
                        ((grid_x) * cell_len)  + (cell_len/2),
                        ((grid_y) * cell_len ) + (cell_len/2)
                    });

                    grid[static_cast<int> (grid_y)*grid_s  + static_cast<int> (grid_x)] = Filled;
                    std::cout<<grid_x<<","<<grid_y<<std::endl;
                    rt.setFillColor(sf::Color::White);
                    arr.push_back(rt);
                    shapes++;
                }
            }

        }

        window.clear();   
        
        for(int i = 0 ; i< shapes;i++){

            if(arr[i].getPosition().y != height-(cell_len)/2){
                int grid_x = ((static_cast<int>(arr[i].getPosition().x) / cell_len));
                int grid_y = ((static_cast<int>(arr[i].getPosition().y) / cell_len));

                if(grid[((grid_y)*(grid_s) + grid_x) + grid_s] == Empty){

                    grid[(grid_y)*(grid_s) + grid_x] = Empty;

                    arr[i].move({0.0f, static_cast<float>(cell_len)});

                    grid[((grid_y)*(grid_s) + grid_x) + grid_s]  = Filled;
                    
                  }
                else if( (((grid_y)*(grid_s) + grid_x) + grid_s + 1 >= 0 ) && (grid[((grid_y)*(grid_s) + grid_x) + grid_s + 1] == Empty)){
                    grid[(grid_y)*(grid_s) + grid_x] = Empty;
                    arr[i].move({static_cast<float>(cell_len), static_cast<float>(cell_len)});
                    grid[((grid_y)*(grid_s) + grid_x) + grid_s + 1]  = Filled;
                }
                else if( (((grid_y)*(grid_s) + grid_x) + grid_s - 1 >= 0 ) && (grid[((grid_y)*(grid_s) + grid_x) + grid_s - 1] == Empty)){
                    grid[(grid_y)*(grid_s) + grid_x] = Empty;
                    arr[i].move({- static_cast<float>(cell_len), static_cast<float>(cell_len)});
                    grid[((grid_y)*(grid_s) + grid_x) + grid_s - 1]  = Filled;
                }
            }

            

            window.draw(arr[i]);

        }

        window.display();


    }

    return 0;
}