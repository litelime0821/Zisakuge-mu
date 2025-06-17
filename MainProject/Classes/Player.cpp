//
// Player.cpp
//

#include "Player.h"

using namespace HE;


void Player::Load()
{
    sprite_ = Sprite("player1.png");
    RenderingPath->AddSprite(&sprite_, 0);
    RenderingPath->AddSprite(&collision_sprite_, 1);




    heart3_ = Sprite("heart3.png");
    RenderingPath->AddSprite(&heart3_, -50);
    heart2_ = Sprite("heart2.png");
    RenderingPath->AddSprite(&heart2_, -50);
    heart1_ = Sprite("heart1.png");
    RenderingPath->AddSprite(&heart1_, -50);
}


void Player::Initialize()
{

    sprite_.params.siz = Math::Vector2(32.0f, 48.0f);
    sprite_.params.pos = Math::Vector2(
        (RenderingPath->GetLogicalWidth() - sprite_.params.siz.x) / 2.0f,
        RenderingPath->GetLogicalHeight() - sprite_.params.siz.y
    );

    sprite_.params.enableDrawRect(Rectf(
        256, 128, sprite_.params.siz.x, sprite_.params.siz.y
    ));

    heart3_.params.siz = Math::Vector2(25.0f, 15.0f);
   


    // 画面に表示する座標、サイズの設定
    sprite_.params.pos.x = 640.0f - 32.0f;
    sprite_.params.pos.y = 320.0f - 48.0f;
    sprite_.params.siz.x = 32.0f;
    sprite_.params.siz.y = 48.0f;

    // 最初のコマと、一コマの大きさを設定
    sprite_.params.enableDrawRect(Math::Vector4(0, 0, 32, 48));
    SetInitialPosition();

    collision_sprite_.params.color = Color(255, 0, 0);  // 色
    collision_sprite_.params.opacity = 0.0f;


    sprite_.anim = Sprite::Anim();
    sprite_.anim.repeatable = true;                       // ループするかしないか
    sprite_.anim.drawRectAnim.frameRate = 2;             // アニメーションの速度
    sprite_.anim.drawRectAnim.frameCount = 3;             // 画像にアニメーションが何コマあるか
    sprite_.anim.drawRectAnim.horizontalFrameCount = 3;


  
    RenderingPath->AddSprite(&sprite_);
}

        void Player::Update()
        { 
            if (sprite_.params.pos.x >= 2560.0f)
                sprite_.params.pos.x = -1280.0f;
            else if (sprite_.params.pos.x <= -1280.0f)
                sprite_.params.pos.x = 2560.0f;

            Math::Vector2 direction;
            if (InputSystem.Keyboard.isPressed.Right) {
                direction += Math::Vector2(1, 0);
            }
            if (InputSystem.Keyboard.isPressed.Left) {
                direction += Math::Vector2(-1, 0);
            }
            if (InputSystem.Keyboard.isPressed.Down) {
                direction += Math::Vector2(0, 1);
            }
            if (InputSystem.Keyboard.isPressed.Up) {
                direction += Math::Vector2(0, -1);
            }

            // 矢印の長さを1にする
            direction.Normalize();

            auto prev_pos = sprite_.params.pos;
            sprite_.params.pos += direction * 256.0f * Time.deltaTime;

            // 画面の外に出ないようにする
            
            sprite_.params.pos.y = std::clamp(sprite_.params.pos.y, 0.0f, 720.0f - 48.0f);

            if (InputSystem.Keyboard.isPressed.Up) {
                sprite_.params.drawRect.y = 48*3;
          
                if (sprite_.params.drawRect.x < 96.0f) {
                    sprite_.params.drawRect.x += 96.0f;
                
                }
            }
            else if (InputSystem.Keyboard.isPressed.Down){
                sprite_.params.drawRect.y = 0;
              
                if( sprite_.params.drawRect.x >= 96.0f) {
                    sprite_.params.drawRect.x -= 96.0f;
                    //sprite_.anim.drawRectAnim.frameRate = 2;
                }
            }
            else if (InputSystem.Keyboard.isPressed.Left) {
                sprite_.params.drawRect.y = 48;  
              
               if ( sprite_.params.drawRect.x >= 96.0f) {
                    sprite_.params.drawRect.x -= 96.0f;
                   // sprite_.anim.drawRectAnim.frameRate = 2;
                }
            }
            else if (InputSystem.Keyboard.isPressed.Right) {
              
                sprite_.params.drawRect.y = 48*2;
               if ( sprite_.params.drawRect.x >= 96.0f) {
                    sprite_.params.drawRect.x -= 96.0f;
                    //sprite_.anim.drawRectAnim.frameRate = 2;
                }
            }
            else {
                if (sprite_.params.drawRect.x >= 96.0f) {
                    sprite_.params.drawRect.x -= 96.0f;
                   // sprite_.anim.drawRectAnim.frameRate = 2;
                }
            }
            heart3_.params.pos = sprite_.params.pos + Math::Vector2(3.0f, -15.0f);
        }



Math::Rectangle Player::GetCollision()
{
    if (sprite_.params.pos.x < 0 || sprite_.params.pos.x > 1280) {
        return Math::Rectangle();
    }
        Math::Rectangle collision;
        collision.x = (long)sprite_.params.pos.x;
        collision.y = (long)sprite_.params.pos.y;
        collision.width = (long)sprite_.params.siz.x;
        collision.height = (long)sprite_.params.siz.y;


        collision_sprite_.params.pos.x = (float)collision.x;
        collision_sprite_.params.pos.y = (float)collision.y;
        collision_sprite_.params.siz.x = (float)collision.width;
        collision_sprite_.params.siz.y = (float)collision.height;

        return collision;

}


void Player::OnCollision()
{
    SetInitialPosition();
    sprite_.params.pos = Math::Vector2(

        (RenderingPath->GetLogicalWidth() - sprite_.params.siz.x) / 2.0f,
        RenderingPath->GetLogicalHeight() - sprite_.params.siz.y
    );
    SetHeart(heart_ - 1);
}

void Player::SetInitialPosition()
{
    sprite_.params.pos = Math::Vector2(
        (RenderingPath->GetLogicalWidth() - sprite_.params.siz.x) / 2.0f,
        RenderingPath->GetLogicalHeight() - sprite_.params.siz.y
    );
}
void Player::SetHeart(int heart)
{
    heart_ = heart;
    switch (heart) {
    case 1:
        heart3_.SetHidden(true);
        heart2_.SetHidden(true);
        heart1_.SetHidden(false);
        break;
    case 2:
        heart3_.SetHidden(true);
        heart2_.SetHidden(false);
        heart1_.SetHidden(true);
        break;
    case 3:
        heart3_.SetHidden(false);
        heart2_.SetHidden(true);
        heart1_.SetHidden(true);
        break;

    }
}