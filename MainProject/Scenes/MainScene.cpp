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
	for (int i = 0; i < std::size(ya_);i++){
		ya_[i].Load();
}
	Scene::Load();
}

// initialize a variables.
void MainScene::Initialize()
{
	bg_.Initialize();
	player_.Initialize();
	for (int i = 0; i < std::size(ya_);i++) {
		ya_[i].Initialize(Random::GetRandom(100.0f, 1000.0f));
	}
	
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
	for (int i = 0; i < std::size(ya_);i++) {
		ya_[i].Update();
		ya_[i].GetCollision();
	}


	Scene::Update(deltaTime);
}
