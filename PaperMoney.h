#ifndef PAPERMONEY_H_INCLUDED
#define PAPERMONEY_H_INCLUDED
#include <allegro5/bitmap.h>
#include <memory>
#include <vector>

#include "Sprite.hpp"

class PlayScene;
class PaperMoney : public Engine::Sprite {
protected:
	float speed;
    float rotateRadian = 2 * ALLEGRO_PI;
	PlayScene* getPlayScene();
public:
    int money;
	PaperMoney(std::string img, float x, float y, float radius, float speed, int money );
	void Update(float deltaTime) override;
	void Draw() const override;
};


#endif // PAPERMONEY_H_INCLUDED
