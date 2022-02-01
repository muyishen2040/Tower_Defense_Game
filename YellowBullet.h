#ifndef YELLOWBULLET_H_INCLUDED
#define YELLOWBULLET_H_INCLUDED
#include "EnemyBullet.h"

class Enemy;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class YellowBullet : public EnemyBullet {
public:
	explicit YellowBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void OnExplode(Turret* turret) override;
};


#endif // YELLOWBULLET_H_INCLUDED
