#ifndef POTATOTURRET_H_INCLUDED
#define POTATOTURRET_H_INCLUDED
#include "Turret.hpp"

class PotatoTurret: public Turret {
public:
	static const int Price;
    PotatoTurret(float x, float y);
	void CreateBullet() override;
};
#endif // POTATOTURRET_H_INCLUDED
