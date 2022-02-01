#ifndef ENEMYBULLET_H_INCLUDED
#define ENEMYBULLET_H_INCLUDED
#include <string>

#include "Sprite.hpp"

class Enemy;
class PlayScene;
class Turret;
namespace Engine {
struct Point;
}  // namespace Engine

class EnemyBullet : public Engine::Sprite {
protected:
	float speed;
	float damage;
	Enemy* parent;
	PlayScene* getPlayScene();
	virtual void OnExplode(Turret* turret);
public:
	Turret* Target = nullptr;
	explicit EnemyBullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent);
	void Update(float deltaTime) override;
};


#endif // ENEMYBULLET_H_INCLUDED
