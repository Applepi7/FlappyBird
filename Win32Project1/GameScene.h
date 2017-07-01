#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"

#include "Bird.h"
#include "Block.h"

#include <list>
using namespace std;

class GameScene :
	public ZeroIScene
{
private:
	pair<float, float> spawnTimer;

public:
	GameScene();
	~GameScene();

	Bird* bird;
	list<Block*> blockList;

	ZeroSprite* background;


	void Update(float eTime) override;
	void Render() override;

	void IsCollision();
	void SpawnBlock(float eTime);
	void CheckOut();
};

