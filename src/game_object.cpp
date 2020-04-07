#include "game_object.h"

GameObject::GameObject(int x, int y, int w, int h)
{
    center_x = x;
    center_y = y;
    width = w;
    height = h;
}

int GameObject::get_x()
{
    return center_x;
}

int GameObject::get_y()
{
    return center_y;
}

int GameObject::get_width()
{
    return width;
}

int GameObject::get_height()
{
    return height;
}

void GameObject::set_x(int x)
{
    center_x = x;
}

void GameObject::set_y(int y)
{
    center_y = y;
}

void GameObject::set_width(int w)
{
    width = w;
}

void GameObject::set_height(int h)
{
    height = h;
}

void GameObject::scale(float x, float y)
{
    object_Sprite.scale(sf::Vector2f(x, y));
}

void GameObject::set_sprite_src(std::string route)
{
    object_Texture.loadFromFile(route);
    object_Sprite.setTexture(object_Texture);
    object_Sprite.setPosition(center_x - (width / 2), center_y - (height / 2));
}


void GameObject::update()
{
    object_Sprite.setPosition(center_x - (width/2), center_y - (height/2));
}

//debug rectangle
void GameObject::debug(sf::RenderWindow &window)
{
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setPosition(sf::Vector2f(center_x - (width / 2), center_y - (height / 2)));
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineThickness(2.0f);
    rect.setOutlineColor(sf::Color::Red);
    window.draw(rect);
}

sf::Sprite GameObject::get_sprite_src()
{
    return object_Sprite;
}

void GameObject::draw(sf::RenderWindow &window)
{
    window.draw(get_sprite_src());
}

bool GameObject::iscoll(GameObject &other)
{
    int minX1 = center_x - width/2;
    int maxX1 = center_x + width/2;
    int minY1 = center_y - height/2;
    int maxY1 = center_y + height/2;

    int minX2 = other.center_x - other.width / 2;
    int maxX2 = other.center_x + other.width / 2;
    int minY2 = other.center_y - other.height / 2;
    int maxY2 = other.center_y + other.height / 2;

    if (maxX1 > minX2 && maxX2 > minX1 &&
        maxY1 > minY2 && maxY2 > minY1)
    {
        return true;
    }
    else
        return false;
}
