
#pragma once

#include "../MainProject/HuEngine.h"

class Player;
class ya {
public:
    void Load();
    void Initialize(float speed);
    void Update();
   HE::Math::Rectangle GetCollision();
   void OnCollision();

private:
    void SetRandomPosition();
    HE::Sprite sprite_;
    HE::Math::Vector2 direction_;
    float             speed_;
    HE::Sprite collision_sprite_;


};