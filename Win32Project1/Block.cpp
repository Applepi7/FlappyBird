#include "stdafx.h"
#include "Block.h"

#include "Global.h"

Block::Block() : isMove(true), score(0)
{
	Dobstacle = new ZeroSprite("Resource/Block/Dobstacle.png");
	Uobstacle = new ZeroSprite("Resource/Block/Uobstacle.png");
	scoreTrigger = new ZeroSprite("Resource/Block/scoreTrigger.png");
	PushScene(Dobstacle);
	PushScene(Uobstacle);
	PushScene(scoreTrigger);
	
}


Block::~Block()
{
}

void Block::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	Uobstacle->Update(eTime);
	Dobstacle->Update(eTime);
	scoreTrigger->Update(eTime);
	MoveX(eTime);
}

void Block::Render()
{
	ZeroIScene::Render();
	Uobstacle->Render();
	Dobstacle->Render();
	scoreTrigger->Render();
}

void Block::MoveX(float eTime)
{
	if(isMove)
		AddPosX(-110 * eTime);
}
