#ifndef CHIPBULLET_H_INCLUDED
#define CHIPBULLET_H_INCLUDED
#include "EnemyBullet.h"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class ChipBullet : public EnemyBullet {
public:
	explicit ChipBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* turret) override;
};


#endif // CHIPBULLET_H_INCLUDED
