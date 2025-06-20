//
// BG.cpp
//

#include "BG.h"

using namespace HE;

void BG::Load()
{
    sprite_ = Sprite("BG.jpg");
    RenderingPath->AddSprite(&sprite_, -100);
    mc_ = Sound("MS.wav", Sound::LoopCount::BGM);
}

void BG::Initialize()
{

    sprite_.params.siz = sprite_.GetTextureSize();
    sprite_.params.pos = Math::Vector2(0.0f, 0.0f);
    mc_.PlayFromTop();
}

void BG::Update()
{

}
