#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"


class Block :
	public ZeroIScene
{
public:
	Block();
	~Block();

	ZeroSprite* Uobstacle;
	ZeroSprite* Dobstacle;
	ZeroSprite* scoreTrigger;

	bool isMove;

	int score;

	void Update(float eTime) override;
	void Render() override;

	void MoveX(float eTime);
};

