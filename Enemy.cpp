#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>
#include <utility>

#include "AudioHelper.hpp"
#include "Bullet.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "ExplosionEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "LOG.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Turret.hpp"

PlayScene* Enemy::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
void Enemy::OnExplode() {
	getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(Position.x, Position.y));
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distId(1, 3);
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);
	for (int i = 0; i < 10; i++) {
		// Random add 10 dirty effects.
		getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-" + std::to_string(distId(rng)) + ".png", dist(rng), Position.x, Position.y));
	}
}
Enemy::Enemy(std::string img, float x, float y, float radius, float speed, float hp, int money, float coolDown) :
	Engine::Sprite(img, x, y), speed(speed), hp(hp), money(money), coolDown(coolDown) {
	CollisionRadius = radius;
	reachEndTime = 0;
	Velocity = Engine::Point(speed , 0);
	target = Engine::Point(PlayScene::EndGridPointx , static_cast<int>(floor(Position.y / PlayScene::BlockSize))) * PlayScene::BlockSize + Engine::Point(PlayScene::BlockSize / 2, PlayScene::BlockSize / 2);
}
void Enemy::Hit(float damage) {
	hp -= damage;
	if (hp <= 0) {
		OnExplode();
		// Remove all turret's reference to target.
		for (auto& it: lockedTurrets)
			it->Target = nullptr;
		for (auto& it: lockedBullets)
			it->Target = nullptr;
		getPlayScene()->EarnMoney(money);
		getPlayScene()->EnemyGroup->RemoveObject(objectIterator);
		AudioHelper::PlayAudio("explosion.wav");
	}
}
void Enemy::Update(float deltaTime) {
	float remainSpeed = speed * deltaTime;
	Position.x -= Velocity.x * deltaTime;
	Position.y += Velocity.y * deltaTime;
    //Sprite::Update(deltaTime);
    PlayScene* scene = getPlayScene();
	///////////
	if (Target!=nullptr) {
		if (Target->Position.x > Position.x&& Target->Position.y <= Position.y  && Position.y < Target->Position.y+scene->BlockSize) {
			Target = nullptr;
		}
		// Shoot reload.
		reload -= deltaTime;
		if (reload <= 0) {
			// shoot.
			reload = coolDown;
			CreateBullet();
		}
	}
	if (!Target) {
		// Lock first seen target.
		// Can be improved by Spatial Hash, Quad Tree, ...
		// However simply loop through all enemies is enough for this program.
		for (auto& it : scene->TowerGroup->GetObjects()) {
            if (it->Position.x < Position.x && it->Position.y >= Position.y  && it->Position.y < Position.y+scene->BlockSize) {
				Target = dynamic_cast<Turret*>(it);
				break;
			}
		}
	}
	///////////
	const int x = this->Position.x / PlayScene::BlockSize;
    const int y = this->Position.y / PlayScene::BlockSize;
	if(x>=1&&scene->mapState[y][x-1]==PlayScene::TILE_OCCUPIED){
        Velocity.x = 0;
	}
	else{
        Velocity.x = speed;
	}
	if(Position.x <= PlayScene::EndGridPointx * PlayScene::BlockSize + PlayScene::BlockSize / 2 + 75){
		Hit(hp);
		getPlayScene()->Hit();
		reachEndTime = 0;
		return;
	}
	Engine::Point vec = target - Position;
	reachEndTime = (vec.Magnitude() - remainSpeed) / speed;

}
void Enemy::Draw() const {
	Sprite::Draw();
	if (PlayScene::DebugMode) {
		// Draw collision radius.
		al_draw_circle(Position.x, Position.y, CollisionRadius, al_map_rgb(255, 0, 0), 2);
	}
}
void Enemy::minusSpeed(float dec){
    speed-=dec;
}
float Enemy::GetSpeed(){
    return speed;
}
