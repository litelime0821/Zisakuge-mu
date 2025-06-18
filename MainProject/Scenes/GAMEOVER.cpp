//
// GAMEOVER.cpp
//

#include "GAMEOVER.h"
#include "DontDestroyOnLoad.h"

using namespace HE;

// initialize member variables.
GAMEOVER::GAMEOVER()
{

}

// rearrange UI to fit the size.
void GAMEOVER::ResizeLayout()
{
    Scene::ResizeLayout();



}

// load resources.
void GAMEOVER::Load()
{
    sprite_ = Sprite("GAMEOVER.png");
    RenderingPath->AddSprite(&sprite_, 0);
    GO = Sound("GO.wav", Sound::LoopCount::BGM);
    PD_.Load();

    Scene::Load();
}

// initialize a variables.
void GAMEOVER::Initialize()
{
    sprite_.params.siz = sprite_.GetTextureSize();
    sprite_.params.pos = Math::Vector2(0.0f, 0.0f);
    GO.PlayFromTop();
    PD_.Initialize();
    PD_.SetScore(DontDestroy.score_);
}

// releasing resources required for termination.
void GAMEOVER::Terminate()
{

}

// updates the scene.
void GAMEOVER::Update(float deltaTime)
{
    if (InputSystem.Keyboard.wasPressedThisFrame.Space)
        SceneManager.SetNextScene(NextScene::TitleScene);


    Scene::Update(deltaTime);
}
