#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
//#include "IceCreamBullet.hpp"
#include "Group.hpp"
#include "Shovel.h"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Enemy.hpp"

const int Shovel::Price = 0;
Shovel::Shovel(float x, float y) :
    // TODO 2 (2/8): You can imitate the 2 files: 'FreezeTurret.hpp', 'FreezeTurret.cpp' to create a new turret.
	Turret("play/bomb.png", x, y, 0, 0, Price, 0.5) {
	// Move center downward, since we the turret head is slightly biased upward.
	Anchor.y += 8.0f / GetBitmapHeight();
}
void Shovel::CreateBullet(){

};
