#pragma once

#include "../HuEngine.h"
#include "../Classes/BG.h"
#include "../Classes/Player.h"
#include "../Classes/ya.h"
#include "../Classes/PlayerDate.h"


class MainScene : public HE::Scene
{
public:
	MainScene();
	virtual ~MainScene() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;

private:
	BG bg_;
	Player player_;
	ya ya_[50];
	int score_;

	int drop_;
	float elapsed_time_;
	float time = 0.0f;

};
