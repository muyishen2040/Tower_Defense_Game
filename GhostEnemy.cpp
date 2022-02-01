#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "RocketBullet.h"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
#include "Turret.hpp"
#include "GhostEnemy.h"

GhostEnemy::GhostEnemy(int x, int y) : Enemy("play/enemy-5.png", x, y, 16, 150, 10, 90, 0.5) {
	// Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
	// and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}
void GhostEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(-1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EnemyBulletGroup->AddNewObject(new RocketBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
