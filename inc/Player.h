#include "../inc/game_object.h"

class Player : public GameObject{
protected:
    enum class Sex
    {
        MALE,
        FEMALE,
        OTHER
    } sex;

public:
    Player() = default;
    Player(int x, int y, int w, int h);
    virtual void init(int x, int y, int w, int h);
    void setSex();
    Sex getSex();

};