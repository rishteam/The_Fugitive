#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameObject{
public:
    GameObject() = default;
    GameObject(int x, int y, int w, int h);
    ~GameObject() {};
    virtual void init(int x, int y, int w, int h){};
    int get_x();
    int get_y();
    int get_width();
    int get_height();
    void set_x(int x);
    void set_y(int y);
    void set_width(int w);
    void set_height(int h);
    void scale(float x, float y);
    void set_sprite_src(std::string route);
    sf::Sprite get_sprite_src();
    void debug(sf::RenderWindow &window);
    void update();
    void draw(sf::RenderWindow &window);
    bool iscoll(GameObject &other);

protected:
    int width, height;
    int center_x, center_y;
    sf::Texture object_Texture;
    sf::Sprite object_Sprite;
};