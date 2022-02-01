#ifndef SHOVEL_H_INCLUDED
#define SHOVEL_H_INCLUDED
#include "Turret.hpp"

class Shovel: public Turret {
public:
    static const int Price;
    Shovel(float x, float y);
    void CreateBullet() override;
};
#endif // SHOVEL_H_INCLUDED
