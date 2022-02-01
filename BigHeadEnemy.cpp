#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "ChickenBullet.h"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
#include "BigHeadEnemy.h"
#include "Turret.hpp"

BigHeadEnemy::BigHeadEnemy(int x, int y) : Enemy("play/enemy-4.png", x, y, 18, 90, 60, 80, 3.5) {
	// Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
	// and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}
void BigHeadEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(-1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EnemyBulletGroup->AddNewObject(new ChickenBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
