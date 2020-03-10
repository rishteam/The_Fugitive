#include <game_object.h>

GameObject::GameObject(int x, int y, int w, int h)
{
    center_x = x;
    center_y = y;
    width = w;
    height = h;
}

void GameObject::move_left(int dis)
{
    center_x -= dis;
}

void GameObject::move_right(int dis)
{
    center_x += dis;
}

void GameObject::move_up(int dis)
{
    center_y -= dis;
}

void GameObject::move_down(int dis)
{
    center_y += dis;
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

void GameObject::set_sprite_src(std::string route, float pos_x, float pos_y)
{
    object_Texture.loadFromFile(route);
    object_Sprite.setTexture(object_Texture);
    object_Sprite.setPosition(pos_x, pos_y);
}

void GameObject::update()
{
    object_Sprite.setPosition(center_x, center_y);
}

void GameObject::debug(sf::RenderWindow &window)
{
    printf("%d %d %d %d\n", get_x(), get_y(), get_width(), get_height());
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setPosition(sf::Vector2f(center_x - width / 2, center_y - height / 2));
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

bool GameObject::coll(GameObject &other)
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
