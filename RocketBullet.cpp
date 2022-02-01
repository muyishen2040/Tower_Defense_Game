#include <allegro5/base.h>
#include <random>
#include <string>
#include "Turret.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "RocketBullet.h"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

class Turret;
class Enemy;

RocketBullet::RocketBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent) :
	EnemyBullet("play/bullet-8.png", 500, 0.5, position, forwardDirection, rotation + ALLEGRO_PI , parent) {
	// TODO 2 (1/8): You can imitate the 2 files: 'FireBullet.hpp', 'FireBullet.cpp' to create a new bullet.
}
void RocketBullet::OnExplode(Turret* turret) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
	getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), turret->Position.x, turret->Position.y));
}
