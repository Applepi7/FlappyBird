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
	//, "04B_19_" ,"Resource/Font/04B_19_.TTF"

	PushScene(titleText);
	PushScene(background);
	PushScene(enterText);

	titleText->SetPos(180, 100);
	enterText->SetPos(165, 575);
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
