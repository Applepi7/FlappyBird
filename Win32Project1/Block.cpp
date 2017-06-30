#include "stdafx.h"
#include "Block.h"


Block::Block()
{
	Dobstacle = new ZeroSprite("Resource/Block/Dobstacle.png");
	Uobstacle = new ZeroSprite("Resource/Block/Uobstacle.png");
	PushScene(Dobstacle);
	PushScene(Uobstacle);

	Uobstacle->SetPos(400, -100);
	Dobstacle->SetPos(400, Uobstacle->Pos().y + 700);
}


Block::~Block()
{
}

void Block::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	Uobstacle->Update(eTime);
	Dobstacle->Update(eTime);
	MoveX(eTime);
}

void Block::Render()
{
	ZeroIScene::Render();
	Uobstacle->Render();
	Dobstacle->Render();
}

void Block::MoveX(float eTime)
{
	AddPosX(-50 * eTime);
}
