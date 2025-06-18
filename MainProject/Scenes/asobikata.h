#pragma once

#include "../HuEngine.h"

class Asobi : public HE::Scene
{
public:
	Asobi();
	virtual ~Asobi() { Terminate(); }

	void ResizeLayout() override;

	void Load() override;
	void Initialize() override;
	void Terminate() override;

	void Update(float deltaTime) override;

private:
	HE::Sprite sprite_;


};
