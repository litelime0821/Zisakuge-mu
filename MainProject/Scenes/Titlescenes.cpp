//
// Titlescenes.cpp
//

#include "Titlescenes.h"

using namespace HE;

// initialize member variables.
Titlescenes::Titlescenes()
{

}

// rearrange UI to fit the size.
void Titlescenes::ResizeLayout()
{
    Scene::ResizeLayout();

  
}

// load resources.
void Titlescenes::Load()
{
  sprite_ = Sprite("title.png");
    RenderingPath->AddSprite(&sprite_, 0);
    title = Sound("title.wav", Sound::LoopCount::BGM);

  

    Scene::Load();
}

// initialize a variables.
void Titlescenes::Initialize()
{
  sprite_.params.siz = sprite_.GetTextureSize();
    sprite_.params.pos = Math::Vector2(0.0f, 0.0f);
    title.PlayFromTop();
}

// releasing resources required for termination.
void Titlescenes::Terminate()
{

}

// updates the scene.
void Titlescenes::Update(float deltaTime)
{
    if (InputSystem.Keyboard.wasPressedThisFrame.OemQuestion)
        SceneManager.SetNextScene(NextScene::asobikataScene);
    if (InputSystem.Keyboard.wasPressedThisFrame.Space)
        SceneManager.SetNextScene(NextScene::MainScene);

    Scene::Update(deltaTime);
}
