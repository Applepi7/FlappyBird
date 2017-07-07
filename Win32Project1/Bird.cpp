#include "stdafx.h"
#include "Bird.h"

#include "ZeroInputManager.h"


Bird::Bird() : moveY(0), jumpPower(400), floorY(0), gravity(400)
{
	bird = new ZeroAnimation(1.f);
	for (int i = 1; i <= 3; i++) {
		bird->PushSprite("Resource/Player/Fly_%d.png", i);
	}
	PushScene(bird);
	
	SetPos(100, 200);
}

Bird::~Bird()
{
}

void Bird::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	bird->Update(eTime);
	
	AddPosY(moveY * eTime);
	Fly(eTime);
	if (Pos().y <= floorY) {
		moveY += gravity * eTime;
		floorY = 0;
	} 
	moveY += gravity * eTime;

}

void Bird::Render()
{
	ZeroIScene::Render();
	bird->Render();
}

void Bird::Fly(float eTime)
{
	if (ZeroInputMgr->GetKey(VK_SPACE) == INPUTMGR_KEYDOWN)
	{
		moveY = -jumpPower;
		floorY = Pos().y - 100;
	}
	
}

