
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

void ya::Initialize( float speed)
{
   // constexpr float DISTNACE = 350.0f;
    sprite_.params.siz = Math::Vector2(211.0f, 25.0f);
    sprite_.params.pivot = Math::Vector2(1.0f, 0.5f);
    //sprite_.params.pos = Math::Vector2(640.0f, 360.0f);
    sprite_.params.enableDrawRect(Rectf(
        0, 0, sprite_.params.siz.x, sprite_.params.siz.y
    ));

    SetRandomPosition();

   // sprite_.params.rotation = XMConvertToRadians(Random::GetRandom(0.0f, 360.0f));
    speed_ = speed;

    collision_sprite_.params.color = Color(255, 0, 0);  // F
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

void ya::SetRandomPosition()
{
    const int SIDE = Random::GetRandom(0, 3);
    Math::Vector2 target;
    switch (SIDE) {
    case 0: // ‰E
        sprite_.params.pos.x = RenderingPath->GetLogicalWidth();
        sprite_.params.pos.y = Random::GetRandom(0.0f, 720.0f);
      

        target.x = -(float)sprite_.params.siz.x;
        target.y = Random::GetRandom(-360.0f, 1080.0f);
        break; 
    case 1://¶
        sprite_.params.pos.x = 0;
        sprite_.params.pos.y = Random::GetRandom(0.0f, 720.0f);

        target.x = RenderingPath->GetLogicalWidth();
        target.y = Random::GetRandom(-360.0f, 1080.0f);

        break;
    case 2://ã
        sprite_.params.pos.x = Random::GetRandom(-360.0f, 1080.0f);
        sprite_.params.pos.y = 0;
    

        target.y = RenderingPath->GetLogicalWidth();
        target.x = Random::GetRandom(-360.0f, 1640.0f);
        break;
    case 3://‰º
        sprite_.params.pos.y = RenderingPath->GetLogicalHeight();
        sprite_.params.pos.x = Random::GetRandom(-360.0f, 1640.0f);
        

        target.y = 0;
        target.x = Random::GetRandom(-360.0f, 1080.0f);
        break;
    }
    direction_ = target - sprite_.params.pos;
    direction_.Normalize();
    sprite_.params.rotation = atan2(direction_.y ,direction_.x);
}

void ya::OnCollision() {

}

Math::Rectangle ya::GetCollision()
{
    Math::Rectangle collision;
    collision.x = (long)sprite_.params.pos.x-8;
    collision.y = (long)sprite_.params.pos.y-8;
    collision.width = 16;
    collision.height = 16;

    collision_sprite_.params.pos.x = (float)collision.x;
    collision_sprite_.params.pos.y = (float)collision.y;
    collision_sprite_.params.siz.x = (float)collision.width;
    collision_sprite_.params.siz.y = (float)collision.height;



    return collision;
}