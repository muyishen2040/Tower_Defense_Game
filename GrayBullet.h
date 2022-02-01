#ifndef GRAYBULLET_H_INCLUDED
#define GRAYBULLET_H_INCLUDED
#include "EnemyBullet.h"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class GrayBullet : public EnemyBullet {
public:
	explicit GrayBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* turret) override;
};
#endif // GRAYBULLET_H_INCLUDED
