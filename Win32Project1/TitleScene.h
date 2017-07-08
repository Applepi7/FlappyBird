#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroFont.h"


class TitleScene :
	public ZeroIScene
{
public:
	TitleScene();
	~TitleScene();

	ZeroSprite* titleText;
	ZeroSprite* background;

	ZeroFont* enterText;

	void Update(float eTime) override;
	void Render() override;
};

