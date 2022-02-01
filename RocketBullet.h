#ifndef ROCKETBULLET_H_INCLUDED
#define ROCKETBULLET_H_INCLUDED
#include "EnemyBullet.h"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class RocketBullet : public EnemyBullet {
public:
	explicit RocketBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* turret) override;
};
#endif // ROCKETBULLET_H_INCLUDED
