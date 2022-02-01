#ifndef TURRET_HPP
#define TURRET_HPP
#include <allegro5/base.h>
#include <list>
#include <string>

#include "Sprite.hpp"

class Enemy;
class PlayScene;

class Turret: public Engine::Sprite {
protected:
    int price;
    float hp;
    float coolDown;
    float reload = 0;
    float rotateRadian = 2 * ALLEGRO_PI;
    std::list<Turret*>::iterator lockedTurretIterator;
    PlayScene* getPlayScene();
    // Reference: Design Patterns - Factory Method.
    virtual void OnExplode();
    virtual void CreateBullet() = 0;

public:
    bool Enabled = true;
    bool Preview = false;
    Enemy* Target = nullptr;
    Turret(/*std::string imgBase,*/std::string imgTurret, float x, float y, float radius,float hp, int price, float coolDown);
    void Hit(float damage);
    void Update(float deltaTime) override;
    void Draw() const override;
	int GetPrice() const;
	float GetHP() const;
};
#endif // TURRET_HPP
