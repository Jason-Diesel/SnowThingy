#pragma once
#include "DefaultVariableToScene.h"
#include "Billboard.h"

class Snow
{
public:
	Snow(DefaultVariableToScene* basic);
	void update();
	void render();
private:
	DefaultVariableToScene* basic;

	GameObject* plane1;
	GameObject* snow;
	//create an particle effect
	uint32_t snowHeightTexture;

	BillboardGroup snowParticles;
	uint32_t billboardShader;
};