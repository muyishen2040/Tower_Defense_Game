#ifndef CHICKENBULLET_H_INCLUDED
#define CHICKENBULLET_H_INCLUDED
#include "EnemyBullet.h"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class ChickenBullet : public EnemyBullet {
public:
	explicit ChickenBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* turret) override;
};
#endif // CHICKENBULLET_H_INCLUDED
