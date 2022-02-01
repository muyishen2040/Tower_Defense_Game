#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Money1000.h"

Money1000::Money1000(int x, int y) : PaperMoney("play/money1000.png", x, y, 18, 300, 1000) {
	// Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
	// and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}
