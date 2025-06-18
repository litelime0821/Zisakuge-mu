//
// MainScene.cpp
//

#include "MainScene.h"
#include "DontDestroyOnLoad.h"

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
	player_.SetHeart(3);
	for (int i = 0; i < std::size(ya_);i++) {
		ya_[i].Initialize(Random::GetRandom(100.0f, 1000.0f));
	}
	
	drop_ = 3;
}

// releasing resources required for termination.
void MainScene::Terminate()
{

}

// updates the scene.
void MainScene::Update(float deltaTime)
{
	time += deltaTime; 

	bg_.Update();
	player_.Update();
	for (int i = 0; i < drop_;i++) {
		ya_[i].Update();
		ya_[i].GetCollision();
	
	}

	Math::Rectangle player_collision = player_.GetCollision();
	for (int i = 0; i < drop_; ++i) {
		Math::Rectangle ya_collsion = ya_[i].GetCollision();
		if (player_collision.Intersects(ya_collsion)) {
			player_.OnCollision();
			ya_[i].OnCollision();
			if(player_.GetHeart()<1)


			break;
		}
	}

	elapsed_time_ += deltaTime;
	if (elapsed_time_ >= 5.0f) {
		if (drop_ < std::size(ya_)) {
			++drop_;
			elapsed_time_ = 0;
		}
	}
	if (player_.GetHeart() == 0) {
		DontDestroy.score_ = time * 10;
		SceneManager.SetNextScene(NextScene::GAMEOVERScene);
	}

	Scene::Update(deltaTime);
}
