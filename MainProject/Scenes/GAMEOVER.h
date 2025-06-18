#pragma once

#include "../HuEngine.h"
#include "../Classes/PlayerDate.h"

class GAMEOVER: public HE::Scene
{
public:
	GAMEOVER();
	virtual ~GAMEOVER() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;

private:
	HE::Sprite sprite_;
	HE::Sound GO;
	PlayerData PD_;

};
