#pragma once
#include "ZeroIScene.h"
#include "ZeroAnimation.h"


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

	ZeroAnimation* bird;
	
	void Update(float eTime) override;
	void Render() override;
	void Fly(float eTime);


	Bird();
	~Bird();
};

