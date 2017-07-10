#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroSoundManager.h"
#include "ZeroFont.h"

#include "Bird.h"
#include "Block.h"
#include "Ground.h"

#include <list>
using namespace std;

class GameScene :
	public ZeroIScene
{

public:
	GameScene();
	~GameScene();

	Bird* b;
	Ground* ground;
	list<Block*> blockList;

	pair<float, float> spawnTimer;
	pair<float, float> scoreTimer;

	ZeroSprite* background;
	ZeroFont* scoreText;

	int score;
	int playNum1;
	int playNum2;

	bool isPlay;
	bool isSpawn;
	bool isScore;

	void Update(float eTime) override;
	void Render() override;

	void IsCollision();
	void SpawnBlock(float eTime);
	void CheckOut();
	void Scoring();
	void PlayHitSound();
	void PlayDeadSound();
};

