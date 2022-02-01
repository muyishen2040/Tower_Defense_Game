#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "YellowBullet.h"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
#include "Turret.hpp"
#include "NormalEnemy.hpp"

NormalEnemy::NormalEnemy(int x, int y) : Enemy("play/enemy-1.png", x, y, 15, 50, 15, 50, 2.5) {
    // TODO 2 (6/8): You can imitate the 2 files: 'NormalEnemy.hpp', 'NormalEnemy.cpp' to create a new enemy.
}
void NormalEnemy::CreateBullet() {
	Engine::Point diff = Engine::Point(-1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->EnemyBulletGroup->AddNewObject(new YellowBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("gun.wav");
}
