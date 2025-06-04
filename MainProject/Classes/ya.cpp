
//
// ya.cpp
//

#include "ya.h"
#include "Player.h"


using namespace HE;

void ya::Load()
{

    sprite_ = Sprite("ya.png");
    RenderingPath->AddSprite(&sprite_, -50);
  
    RenderingPath->AddSprite(&collision_sprite_, 1);
 

}

void ya::Initialize()
{
    constexpr float DISTNACE = 350.0f;
    sprite_.params.siz = Math::Vector2(211.0f, 25.0f);
    sprite_.params.pos = Math::Vector2(640.0f, 360.0f);
    sprite_.params.enableDrawRect(Rectf(
        0, 0, sprite_.params.siz.x, sprite_.params.siz.y
    ));

 sprite_.params.pivot = Math::Vector2(0.5f, 0.5f);
    sprite_.params.rotation = XMConvertToRadians(Random::GetRandom(0.0f, 360.0f));

    int a = Random::GetRandom(1, 4);
    if (a == 1) { //ã‚©‚ç
        sprite_.params.pos.y = -211;
        sprite_.params.pos.x = XMConvertToRadians(Random::GetRandom(0.0f, 1280.0f));
        
    }
    else  if (a == 2) {//¶‚©‚ç
        sprite_.params.pos.x = -211;
        sprite_.params.pos.y = XMConvertToRadians(Random::GetRandom(0.0f, 720.0f));
    }
    else  if (a == 3) {//‰E‚©‚ç
        sprite_.params.pos.x = 1491;
        sprite_.params.pos.x = XMConvertToRadians(Random::GetRandom(0.0f, 1280.0f));
    }
    else  if (a == 4) {//‰º‚©‚ç
        sprite_.params.pos.y = 931;
        sprite_.params.pos.x = XMConvertToRadians(Random::GetRandom(0.0f, 1280.0f));
    }



    collision_sprite_.params.color = Color(255, 0, 0);  // F
    collision_sprite_.params.opacity = 0.5f;
}

void ya::Update()
{
   

    Math::Vector2 direction;
    float r = 400.0f * Time.deltaTime;
    direction.x = r * cos(sprite_.params.rotation);
    direction.y = r * sin(sprite_.params.rotation);

    sprite_.params.pos.x += direction.x;
    sprite_.params.pos.y += direction.y;


    if (sprite_.params.pos.x >= 1280.0f)
        sprite_.params.pos.x = -88.0f;
}

bool ya::CollisionDetect(Player& player)
{
    Math::Rectangle player_collision = player.GetCollision();
    


    Math::Rectangle collision;
    collision.x = (long)sprite_.params.pos.x;
    collision.y = (long)sprite_.params.pos.y;
    collision.width = (long)sprite_.params.siz.x;
    collision.height = (long)sprite_.params.siz.y;
   collision_sprite_.params.pos.x = (float)collision.x;
    collision_sprite_.params.pos.y = (float)collision.y;
    collision_sprite_.params.siz.x = (float)collision.width;
    collision_sprite_.params.siz.y = (float)collision.height;
    player_collision = player.GetCollision();
    if (player_collision.Intersects(collision)) {

        player.OnCollision();
      
        return true;
    }
   
    return false;
}

//void ya::OnCollision() {

//