#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"


class Bird :
	public ZeroIScene
{
private:
	float fallingSpeed;
	float gravity;

	float moveY;
	float jumpPower;
	float floorY;

public:

	ZeroSprite* bird;
	
	void Update(float eTime) override;
	void Render() override;
	void Fly(float eTime);


	Bird();
	~Bird();
};

