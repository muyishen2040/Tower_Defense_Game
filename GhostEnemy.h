#ifndef GHOSTENEMY_H_INCLUDED
#define GHOSTENEMY_H_INCLUDED
#include "Enemy.hpp"

class GhostEnemy : public Enemy {
public:
	GhostEnemy(int x, int y);
	void CreateBullet() override;
};
#endif // GHOSTENEMY_H_INCLUDED
