#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameObject{
public:
    GameObject() = default;
    GameObject(int x, int y, int w, int h);
    ~GameObject() {};
    virtual void init(int x, int y, int w, int h){};
    void move_left(int dis);
    void move_right(int dis);
    void move_up(int dis);
    void move_down(int dis);
    int get_x();
    int get_y();
    int get_width();
    int get_height();
    void set_sprite_src(std::string route, float pos_x, float pos_y);
    sf::Sprite get_sprite_src();
    void debug(sf::RenderWindow &window);
    void update();
    void draw(sf::RenderWindow &window);
    bool coll(GameObject &other);

protected:
    int width, height;
    int center_x, center_y;
    sf::Texture object_Texture;
    sf::Sprite object_Sprite;
};