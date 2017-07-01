#include "stdafx.h"
#include "GameScene.h"

#include "Global.h"

#include <iostream>
using namespace std;

GameScene::GameScene() : spawnTimer(0, 3.f)
{
	bird = new Bird();
	background = new ZeroSprite("Resource/Background/background.png");
	PushScene(bird);
	PushScene(background);
}


GameScene::~GameScene()
{
}

void GameScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	background->Update(eTime);
	bird->Update(eTime);

	for (auto block : blockList) {
		block->Update(eTime);
	}


	IsCollision();
	SpawnBlock(eTime);
	CheckOut();
}

void GameScene::Render()
{
	ZeroIScene::Render();
	background->Render();
	bird->Render();
	for (auto block : blockList) {
		block->Render();
	}
}

void GameScene::IsCollision()
{
	for (auto block = blockList.begin(); block != blockList.end();) {
		if (bird->bird->IsOverlapped((*block)->Uobstacle) || bird->bird->IsOverlapped((*block)->Dobstacle)) {
			PopScene(bird);
			block++;
			if (block == blockList.end()) break;
		}
		else {
			block++;
			if (block == blockList.end()) break;
		}
	}
}

void GameScene::SpawnBlock(float eTime)
{
	spawnTimer.first += eTime;

	if (spawnTimer.first >= spawnTimer.second) {
		Block* block = new Block();
		
		
		block->Uobstacle->SetPos(600, Random(-300, 0));
		block->Dobstacle->SetPos(600, block->Uobstacle->Pos().y + 700);

		blockList.push_back(block);
		PushScene(block);		

		spawnTimer.first = 0;
	}
}

void GameScene::CheckOut()
{
	for (auto block = blockList.begin(); block != blockList.end();) {
		if ((*block)->Pos().x <= -750) {
			PopScene(*block);
			blockList.erase(block++);
		}
		else block++;
	}
}
