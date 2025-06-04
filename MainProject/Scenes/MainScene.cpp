//
// MainScene.cpp
//

#include "MainScene.h"

using namespace HE;

// initialize member variables.
MainScene::MainScene()
{

}

// rearrange UI to fit the size.
void MainScene::ResizeLayout()
{
	Scene::ResizeLayout();



}

// load resources.
void MainScene::Load()
{

	bg_.Load();
	player_.Load();
	ya_.Load();
	Scene::Load();
}

// initialize a variables.
void MainScene::Initialize()
{
	bg_.Initialize();
	player_.Initialize();
	ya_.Initialize(Math::Vector2(0.0f,0.0f), 1000.0f);
}

// releasing resources required for termination.
void MainScene::Terminate()
{

}

// updates the scene.
void MainScene::Update(float deltaTime)
{
	bg_.Update();
	player_.Update();
	ya_.Update();
	


	Scene::Update(deltaTime);
}
