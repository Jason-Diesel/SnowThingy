#pragma once
#include "Scene.h"
#include "Player.h"
#include "TestBeahvior.h"
#include "Snow.h"

class TestScene : public Scene{
public:
	TestScene();
	virtual ~TestScene();
	void init();
	SceneHandlerCalls update(float dt);
	void render();
private:
	GameObject* Sponza;
	Snow* snow;
	GameObject* teddyBear;
	GameObject* player;
	std::vector<Light*> l;
};
