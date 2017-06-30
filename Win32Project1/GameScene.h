#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"

#include "Bird.h"
#include "Block.h"


class GameScene :
	public ZeroIScene
{
public:
	GameScene();
	~GameScene();

	Bird* bird;
	Block* block;

	ZeroSprite* background;

	void Update(float eTime) override;
	void Render() override;

	void IsCollision();
};

