#include "stdafx.h"
#include "TitleScene.h"

#include "ZeroInputManager.h"
#include "ZeroSceneManager.h"
#include "GameScene.h"


TitleScene::TitleScene()
{
	titleText = new ZeroSprite("Resource/Text/title.png");
	background = new ZeroSprite("Resource/Background/background.png");
	enterText = new ZeroFont(40, "Press Enter to Start");

	PushScene(titleText);
	PushScene(background);
	PushScene(enterText);

	titleText->SetPos(180, 100);
	enterText->SetPos(170, 600);
}


TitleScene::~TitleScene()
{
}

void TitleScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	background->Update(eTime);
	titleText->Update(eTime);
	enterText->Update(eTime);

	if (ZeroInputMgr->GetKey(VK_RETURN) == INPUTMGR_KEYON) {
		ZeroSceneMgr->ChangeScene(new GameScene());
	}
}

void TitleScene::Render()
{
	ZeroIScene::Render();
	background->Render();
	titleText->Render();
	enterText->Render();
}
