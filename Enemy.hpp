#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <list>
#include <vector>
#include <string>

#include "Point.hpp"
#include "Sprite.hpp"

class Bullet;
class PlayScene;
class Turret;

class Enemy : public Engine::Sprite {
protected:
	Engine::Point target;
	float speed;
	float hp;
	int money;
	float coolDown;
    float reload = 0;
    float rotateRadian = 2 * ALLEGRO_PI;
	PlayScene* getPlayScene();
	virtual void CreateBullet() = 0;
public:
    virtual void OnExplode();
	float reachEndTime;
	std::list<Turret*> lockedTurrets;
	std::list<Bullet*> lockedBullets;
	Enemy(std::string img, float x, float y, float radius, float speed, float hp, int money, float coolDown );
 	void Hit(float damage);
	void Update(float deltaTime) override;
	void Draw() const override;
	Turret* Target = nullptr;
	void minusSpeed(float dec);
	float GetSpeed();
};
#endif // ENEMY_HPP
