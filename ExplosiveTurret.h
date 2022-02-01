#ifndef EXPLOSIVETURRET_H_INCLUDED
#define EXPLOSIVETURRET_H_INCLUDED
#include "Turret.hpp"
#include "Sprite.hpp"
class ExplosiveTurret: public Turret {
public:
	static const int Price;
    ExplosiveTurret(float x, float y);
	void CreateBullet() override;
};
#endif // EXPLOSIVETURRET_H_INCLUDED
