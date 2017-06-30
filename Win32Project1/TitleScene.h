#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"


class TitleScene :
	public ZeroIScene
{
public:
	TitleScene();
	~TitleScene();

	ZeroSprite* titleText;
	ZeroSprite* background;

	void Update(float eTime) override;
	void Render() override;
};

