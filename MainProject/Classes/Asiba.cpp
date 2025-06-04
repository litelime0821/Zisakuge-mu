//
// Ashiba.cpp
//

#include "Asiba.h"

using namespace HE;

void Ashiba::Load()
{
    sprite_ = Sprite("Ashiba.jpg");
    RenderingPath->AddSprite(&sprite_, 0);
}

void Ashiba::Initialize()
{

    sprite_.params.siz = sprite_.GetTextureSize();
    sprite_.params.pos = Math::Vector2(0.0f, 0.0f);
}

void Ashiba::Update()
{

}