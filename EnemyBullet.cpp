#include "EnemyBullet.h"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"
#include "Turret.hpp"

PlayScene* EnemyBullet::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
void EnemyBullet::OnExplode(Turret* turret) {
}
EnemyBullet::EnemyBullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Enemy* parent) :
	Sprite(img, position.x, position.y), speed(speed), damage(damage), parent(parent) {
	Velocity = forwardDirection * speed;
	Rotation = rotation;
	CollisionRadius = 4;
}
void EnemyBullet::Update(float deltaTime) {
	Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	// Can be improved by Spatial Hash, Quad Tree, ...
	// However simply loop through all enemies is enough for this program.
	for (auto& it : scene->TowerGroup->GetObjects()) {
		Turret* tur = dynamic_cast<Turret*>(it);
		if (!tur->Visible)
			continue;
		if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, tur->Position, tur->CollisionRadius)) {
			OnExplode(tur);
			if(tur->GetHP()-damage<=0){
                parent->Target=nullptr;
			}
			tur->Hit(damage);
			getPlayScene()->EnemyBulletGroup->RemoveObject(objectIterator);
			return;
		}
	}
	// Check if out of boundary.
	if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2, Engine::Point(0, 0), PlayScene::GetClientSize()))
		getPlayScene()->BulletGroup->RemoveObject(objectIterator);
}
