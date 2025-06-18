
#pragma once

#include "../HuEngine.h"

class Player {
public:
	void Load();
	void Initialize();
	void Update();
	HE::Math::Rectangle GetCollision();
	void OnCollision();
	HE::Math::Vector3 GetPosition() const { return sprite_.params.pos; }
	void SetInitialPosition();  
	int GetHeart() const { return heart_; }
    void SetHeart(int heart);		
private:
	HE::Sprite sprite_;
	float playerspeed_ = 0.2f;
	HE::Sprite collision_sprite_;
	   int heart_;
    HE::Sprite heart3_;
    HE::Sprite heart2_;
    HE::Sprite heart1_;
	int inv_;
	float inv_Time_ = 0.0f;
};