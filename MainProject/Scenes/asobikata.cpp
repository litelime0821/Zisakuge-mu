//
// Asobi.cpp
//

#include "Asobikata.h"

using namespace HE;

// initialize member variables.
Asobi::Asobi()
{

}

// rearrange UI to fit the size.
void Asobi::ResizeLayout()
{
    Scene::ResizeLayout();

  
}

// load resources.
void Asobi::Load()
{
  sprite_ = Sprite("asobikata.png");
    RenderingPath->AddSprite(&sprite_, 0);

  

    Scene::Load();
}

// initialize a variables.
void Asobi::Initialize()
{
  sprite_.params.siz = sprite_.GetTextureSize();
    sprite_.params.pos = Math::Vector2(0.0f, 0.0f);
}

// releasing resources required for termination.
void Asobi::Terminate()
{

}

// updates the scene.
void Asobi::Update(float deltaTime)
{
    if (InputSystem.Keyboard.wasPressedThisFrame.OemQuestion)
        SceneManager.SetNextScene(NextScene::TitleScene);

    Scene::Update(deltaTime);
}
