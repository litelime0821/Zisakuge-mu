
#pragma once

#include "../MainProject/HuEngine.h"

class Player;
class ya {
public:
    void Load();
    void Initialize();
    void Update();
   // HE::Math::Rectangle GetCollision();
   // void OnCollision();
    bool CollisionDetect(Player& player);

private:
    HE::Sprite sprite_;
    HE::Sprite 
    HE::Sprite collision_sprite_;


};