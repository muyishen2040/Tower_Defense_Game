#ifndef POISONBULLET_H_INCLUDED
#define POISONBULLET_H_INCLUDED
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class PoisonBullet : public Bullet {
public:
	explicit PoisonBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void OnExplode(Enemy* enemy) override;
};
#endif // POISONBULLET_H_INCLUDED
