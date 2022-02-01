#ifndef BIGHEADENEMY_H_INCLUDED
#define BIGHEADENEMY_H_INCLUDED
#include "Enemy.hpp"

class BigHeadEnemy : public Enemy {
public:
	BigHeadEnemy(int x, int y);
	void CreateBullet() override;
};
#endif // BIGHEADENEMY_H_INCLUDED
