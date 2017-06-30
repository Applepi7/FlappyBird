#include "stdafx.h"
#include "TitleScene.h"

#include "ZeroInputManager.h"
#include "ZeroSceneManager.h"
#include "GameScene.h"


TitleScene::TitleScene()
{
	titleText = new ZeroSprite("Resource/Title/title.png");
	background = new ZeroSprite("Resource/Background/background.png");

	PushScene(titleText);
	PushScene(background);

	titleText->SetPos(180, 100);
}


TitleScene::~TitleScene()
{
}

void TitleScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	background->Update(eTime);
	titleText->Update(eTime);

	if (ZeroInputMgr->GetKey(VK_RETURN) == INPUTMGR_KEYON) {
		ZeroSceneMgr->ChangeScene(new GameScene());
	}
}

void TitleScene::Render()
{
	ZeroIScene::Render();
	background->Render();
	titleText->Render();
}
