#include <allegro5/allegro.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "Collider.hpp"
#include "PaperMoney.h"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "Plane.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Resources.hpp"

PlayScene* PaperMoney::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}

PaperMoney::PaperMoney(std::string img, float x, float y, float radius, float speed, int money) :
	Engine::Sprite(img, x, y), speed(speed), money(money){
	CollisionRadius = radius;
	Velocity = Engine::Point(0 , speed);
}
void PaperMoney::Update(float deltaTime) {
	//float remainSpeed = speed * deltaTime;
	//Position.x -= Velocity.x * deltaTime;
	Position.y += Velocity.y * deltaTime;
	if(Position.y >= PlayScene::EndGridPointy * PlayScene::BlockSize + PlayScene::BlockSize / 2 + 75){
		getPlayScene()->MoneyGroup->RemoveObject(objectIterator);
		return;
	}
}
void PaperMoney::Draw() const {
	Sprite::Draw();
}
