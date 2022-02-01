#ifndef SETTING_SCENE_H_INCLUDED
#define SETTING_SCENE_H_INCLUDED

#include <allegro5/allegro_audio.h>
#include <memory>
#include "IScene.hpp"

class SettingScene final : public Engine::IScene {
private:
	std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
public:
	explicit SettingScene() = default;
	void Initialize() override;
	void Terminate() override;
	void PlayOnClick(int stage);
	void BGMSlideOnValueChanged(float value);
	void SFXSlideOnValueChanged(float value);
};

#endif // SETTING_SCENE_H_INCLUDED
