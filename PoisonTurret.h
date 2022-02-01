#ifndef POISONTURRET_H_INCLUDED
#define POISONTURRET_H_INCLUDED
#include "Turret.hpp"

class PoisonTurret: public Turret {
public:
	static const int Price;
    PoisonTurret(float x, float y);
	void CreateBullet() override;
};
#endif // POISONTURRET_H_INCLUDED
