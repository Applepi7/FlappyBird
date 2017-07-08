#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"


class Ground :
	public ZeroIScene
{
public:
	Ground();
	~Ground();

	bool isMove;

	ZeroSprite* gSprite1;
	ZeroSprite* gSprite2;

	void Update(float eTime) override;
	void Render() override;

};

