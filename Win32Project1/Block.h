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

	void Update(float eTime) override;
	void Render() override;

	void MoveX(float eTime);
};

