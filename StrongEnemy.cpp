#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "GrayBullet.h"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
#include "Turret.hpp"
#include "StrongEnemy.hpp"

StrongEnemy::StrongEnemy(int x, int y) : Enemy("play/enemy-3.png", x, y, 20, 70, 50, 95, 3) {
	// Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
	// and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}
void StrongEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(-1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EnemyBulletGroup->AddNewObject(new GrayBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
