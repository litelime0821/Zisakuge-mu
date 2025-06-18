#pragma once

#include "../HuEngine.h"

class Titlescenes : public HE::Scene
{
public:
	Titlescenes();
	virtual ~Titlescenes() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;

private:
	HE::Sprite sprite_;
	HE::Sound title;

};
