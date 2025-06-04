
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

void ya::Initialize(HE::Math::Vector2 initial, float speed)
{
   // constexpr float DISTNACE = 350.0f;
    sprite_.params.siz = Math::Vector2(211.0f, 25.0f);
    sprite_.params.pivot = Math::Vector2(0.5f, 0.5f);
    //sprite_.params.pos = Math::Vector2(640.0f, 360.0f);
    sprite_.params.enableDrawRect(Rectf(
        0, 0, sprite_.params.siz.x, sprite_.params.siz.y
    ));

    SetRandomPosition();

   // sprite_.params.rotation = XMConvertToRadians(Random::GetRandom(0.0f, 360.0f));
    speed_ = speed;

    collision_sprite_.params.color = Color(255, 0, 0);  // êF
    collision_sprite_.params.opacity = 0.5f;
}

void ya::Update()
{
    sprite_.params.pos += direction_ * speed_ * Time.deltaTime;
    if (sprite_.params.pos.x >= 1280.0f + 20.0f)
        SetRandomPosition();
    else if (sprite_.params.pos.x < -(float)sprite_.params.siz.x - 20.0f)
        SetRandomPosition();
    else if (sprite_.params.pos.y >= 720.0f + 20.0f)
        SetRandomPosition();
    else if (sprite_.params.pos.y < -(float)sprite_.params.siz.y - 20.0f)
        SetRandomPosition();
}

//bool ya::CollisionDetect(Player& player)
//{
//    Math::Rectangle player_collision = player.GetCollision();
//    
//
//
//    Math::Rectangle collision;
//    collision.x = (long)sprite_.params.pos.x;
//    collision.y = (long)sprite_.params.pos.y;
//    collision.width = (long)sprite_.params.siz.x;
//    collision.height = (long)sprite_.params.siz.y;
//   collision_sprite_.params.pos.x = (float)collision.x;
//    collision_sprite_.params.pos.y = (float)collision.y;
//    collision_sprite_.params.siz.x = (float)collision.width;
//    collision_sprite_.params.siz.y = (float)collision.height;
//    player_collision = player.GetCollision();
//    if (player_collision.Intersects(collision)) {
//
//        player.OnCollision();
//      
//        return true;
//    }
//   
//    return false;
//}

void ya::SetRandomPosition()
{
    const int SIDE = Random::GetRandom(0, 0);
    Math::Vector2 target;
    switch (SIDE) {
    case 0: // âE
        sprite_.params.pos.x = RenderingPath->GetLogicalWidth();
        sprite_.params.pos.y = Random::GetRandom(-360.0f, 1080.0f);
      //  if(sprite_.params.pos.y == )

        target.x = -(float)sprite_.params.siz.x;
        target.y = Random::GetRandom(-360.0f, 1080.0f);
        break; 
    case 1://ç∂
        sprite_.params.pos.x = 0;
        sprite_.params.pos.y = Random::GetRandom(-360.0f, 1080.0f);

        target.x = -(float)sprite_.params.siz.x;
        target.y = Random::GetRandom(-360.0f, 1080.0f);

        break;
    case 2://è„

        break;
    case 3://â∫

        break;
    }
    direction_ = target - sprite_.params.pos;
    direction_.Normalize();
}

//void ya::OnCollision() {

//