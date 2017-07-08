#include "stdafx.h"
#include "Ground.h"


Ground::Ground() : isMove(true)
{
	gSprite1 = new ZeroSprite("Resource/Ground/ground.png");
	gSprite2 = new ZeroSprite("Resource/Ground/ground.png");

	PushScene(gSprite1);
	PushScene(gSprite2);

	gSprite1->SetPos(0, 800 - gSprite1->Height());
	gSprite2->SetPos(gSprite1->Pos().x + gSprite1->Width(), 800 - gSprite2->Height());
}


Ground::~Ground()
{
}

void Ground::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	gSprite1->Update(eTime);
	gSprite2->Update(eTime);

	if (isMove) {
		gSprite2->AddPosX(-110 * eTime);
		gSprite1->AddPosX(-110 * eTime);
	}

	if (gSprite2->Pos().x <= 0) {
		gSprite1->SetPosX(gSprite2->Pos().x + gSprite2->Width());
	}
	if (gSprite1->Pos().x <= 0) {
		gSprite2->SetPosX(gSprite1->Pos().x + gSprite1->Width());
	}
}

void Ground::Render()
{
	ZeroIScene::Render();
	gSprite1->Render();
	gSprite2->Render();
}
