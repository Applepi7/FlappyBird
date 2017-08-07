#include "stdafx.h"
#include "GameScene.h"

#include "ZeroSceneManager.h"
#include "ZeroInputManager.h"

#include "Global.h"

#include <iostream>
using namespace std;

GameScene::GameScene() : spawnTimer(0, 2.f), scoreTimer(0.f, 2.f), isSpawn(true), isScore(true), isAlive(true), score(0), playNum1(0), playNum2(0)
{
	b = new Bird();
	ground = new Ground();
	background = new ZeroSprite("Resource/Background/background.png");
	gameoverText = new ZeroSprite("Resource/Text/gameover.png");
	scoreText = new ZeroFont(70, "");
	continueText = new ZeroFont(70, "");
	
	PushScene(b);
	PushScene(background);
	PushScene(scoreText);

	ZeroSoundMgr->PushSound("Resource/Sound/sfx_hit.wav", "hitSound");
	ZeroSoundMgr->PushSound("Resource/Sound/sfx_point.wav", "scoreSound");
	ZeroSoundMgr->PushSound("Resource/Sound/sfx_die.wav", "deadSound");


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
	ground->Update(eTime);
	if (isAlive) {
		b->Update(eTime);
	}
	scoreText->Update(eTime);
	gameoverText->Update(eTime);
	continueText->Update(eTime);

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
	for (auto block : blockList) {
		block->Render();
	}
	ground->Render();
	if (isAlive) {
		b->Render();
	}
	scoreText->Render();
	
	continueText->Render();
	if (!isAlive)
		gameoverText->Render();
}

void GameScene::IsCollision()
{
	for (auto block = blockList.begin(); block != blockList.end();) {
		if (b->bird->IsOverlapped((*block)->Uobstacle) || b->bird->IsOverlapped((*block)->Dobstacle)) {
			b->canFly = false;
			PlayHitSound();
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
		PlayDeadSound();
		ReStart();
		for (auto block : blockList)
		{
			block->isMove = false;
		}
		isAlive = false;
		ground->isMove = false;

		PushScene(gameoverText);
		gameoverText->SetPos(100, 300);
	}
}

void GameScene::SpawnBlock(float eTime)
{
	if (isAlive) {
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
			ZeroSoundMgr->Play("scoreSound");
			score++;
			block++;
			if (block == blockList.end()) break;
		}
		block++;
		if (block == blockList.end()) break;
	}
	
}

void GameScene::PlayHitSound()
{
	if (playNum1 == 0) {
		playNum1++;
		ZeroSoundMgr->Play("hitSound");
	}
}

void GameScene::PlayDeadSound()
{
	if (playNum2 == 0) {
		playNum2++;
		ZeroSoundMgr->Play("deadSound");
	}
}

void GameScene::ReStart()
{
	continueText = new ZeroFont(40, "Press Enter To Restart");
	PushScene(continueText);
	
	continueText->SetPos(150, 450);

	if (ZeroInputMgr->GetKey(VK_RETURN) == INPUTMGR_KEYDOWN) {
		ZeroSceneMgr->ChangeScene(new GameScene());
	}
}
