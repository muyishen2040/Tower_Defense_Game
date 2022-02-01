#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "PoisonBullet.h"
#include "Group.hpp"
#include "PoisonTurret.h"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"
const int PoisonTurret::Price = 200;
PoisonTurret::PoisonTurret(float x, float y) :
    // TODO 2 (2/8): You can imitate the 2 files: 'FreezeTurret.hpp', 'FreezeTurret.cpp' to create a new turret.
	Turret("play/turret-5.png", x, y, 13, 12, Price, 0.5) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void PoisonTurret::CreateBullet() {
	Engine::Point diff = Engine::Point(1,0);
	float rotation = ALLEGRO_PI / 2;
	getPlayScene()->BulletGroup->AddNewObject(new PoisonBullet(Position , diff, rotation, this));
	AudioHelper::PlayAudio("ice.wav");
}
