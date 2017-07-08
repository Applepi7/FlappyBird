#include "stdafx.h"
#include "GameScene.h"

#include "Global.h"

#include <iostream>
using namespace std;

GameScene::GameScene() : spawnTimer(0, 2.f), scoreTimer(0.f, 2.f) ,isSpawn(true), score(0), isScore(true)
{
	b = new Bird();
	ground = new Ground();
	background = new ZeroSprite("Resource/Background/background.png");
	scoreText = new ZeroFont(70, "");
	
	PushScene(b);
	PushScene(background);
	PushScene(scoreText);

	b->SetScale(0.8);

	scoreText->SetPos(280, 100);
}


GameScene::~GameScene()	
{
}

void GameScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	background->Update(eTime);
	b->Update(eTime);
	ground->Update(eTime);
	scoreText->Update(eTime);

	for (auto block : blockList) {
		block->Update(eTime);
	}

	Scoring();
	IsCollision();
	SpawnBlock(eTime);
	CheckOut();
	scoreText->SetString(to_string(score));
}

void GameScene::Render()
{
	ZeroIScene::Render();
	background->Render();
	b->Render();
	for (auto block : blockList) {
		block->Render();
	}
	ground->Render();
	scoreText->Render();
}

void GameScene::IsCollision()
{
	for (auto block = blockList.begin(); block != blockList.end();) {
		if (b->bird->IsOverlapped((*block)->Uobstacle) || b->bird->IsOverlapped((*block)->Dobstacle)) {
			PopScene(b);
			isSpawn = false;
			for (auto iter : blockList)
			{
				iter->isMove = false;
				ground->isMove = false;
			}
		
			block++;
			if (block == blockList.end()) break;
		}
		block++;
		if (block == blockList.end()) break;
	}

	if (b->bird->IsOverlapped(ground->gSprite1) || b->bird->IsOverlapped(ground->gSprite2)) {
		PopScene(b);
		for (auto iter : blockList)
		{
			iter->isMove = false;
			ground->isMove = false;
		}
	}
}

void GameScene::SpawnBlock(float eTime)
{
	spawnTimer.first += eTime;

	if (spawnTimer.first >= spawnTimer.second && isSpawn) {
		Block* block = new Block();
		
		
		block->Uobstacle->SetPos(600, Random(-300, -170));
		block->Dobstacle->SetPos(600, block->Uobstacle->Pos().y + 700);
		block->scoreTrigger->SetPos(600, block->Uobstacle->Pos().y + block->Uobstacle->Height());

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

void GameScene::Scoring()
{
	for (auto block = blockList.begin(); block != blockList.end();) {
		if (b->bird->IsOverlapped((*block)->scoreTrigger)) {
			score++;
			block++;
			if (block == blockList.end()) break;
		}
		block++;
		if (block == blockList.end()) break;
	}
	
}
