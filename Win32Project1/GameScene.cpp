#include "stdafx.h"
#include "GameScene.h"


GameScene::GameScene()
{
	bird = new Bird();
	block = new Block();
	background = new ZeroSprite("Resource/Background/background.png");
	PushScene(bird);
	PushScene(block);
	PushScene(background);
}


GameScene::~GameScene()
{
}

void GameScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	background->Update(eTime);
	block->Update(eTime);
	bird->Update(eTime);

	IsCollision();
}

void GameScene::Render()
{
	ZeroIScene::Render();
	background->Render();
	block->Render();
	bird->Render();
}

void GameScene::IsCollision()
{
	if (bird->bird->IsOverlapped(block->Uobstacle) || bird->bird->IsOverlapped(block->Dobstacle)) {
		PopScene(bird);
	}
}
