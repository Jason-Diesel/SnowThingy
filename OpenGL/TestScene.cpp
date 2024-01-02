#include "TestScene.h"
#include <iostream>

#include <chrono>


TestScene::TestScene()
{
	std::cout << "Run Test Scene" << std::endl;
}

TestScene::~TestScene()
{
}

void TestScene::init()
{
	gfx->vSync(false);
	basic.camera->setPosition(glm::vec3(0,5,0));
	basic.camera->setRotation(glm::vec3(0,0,0));
	Sponza = gh->createGameObject();
	teddyBear = gh->createGameObject();
	teddyBear->addModel(basic.rm->getModel("Bear.fbx"));
	teddyBear->getMaterial().Albedo = basic.rm->getTexture("../Objects/texbear.png");
	teddyBear->getComponent<Transform>("Transform")->position.x = 400;
	teddyBear->getComponent<Transform>("Transform")->position.y = 0;
	teddyBear->getComponent<Transform>("Transform")->position.z = 400;
	teddyBear->getComponent<Transform>("Transform")->rotation.y = 1.633f;
	teddyBear->getComponent<Transform>("Transform")->rotation.x = 2.2f;
	teddyBear->getComponent<Transform>("Transform")->scale.x = 10.0f;
	teddyBear->getComponent<Transform>("Transform")->scale.y = 10.0f;
	teddyBear->getComponent<Transform>("Transform")->scale.z = 10.0f;

	basic.shadowMap->addGameObject(Sponza);
	
	player = gh->createGameObject();
	std::vector<std::pair<std::string, TLVarieble>> playerComponents;
	playerComponents.push_back(std::pair("cam", TLVarieble(basic.camera)));
	playerComponents.push_back(std::pair("mouse", TLVarieble(basic.mouse)));
	playerComponents.push_back(std::pair("keyboard", TLVarieble(basic.keyboard)));
	playerComponents.push_back(std::pair("Transform", TLVarieble(player->getComponent<Transform>("Transform"))));
	player->addBehavior("playerUpdate", new Player(), &playerComponents);
	
	basic.imGuiManager->addGameObject(Sponza, "Sponza");
	basic.imGuiManager->addGameObject(teddyBear, "Teddy");

	l.push_back(new DirectionalLight(glm::vec3(0,5,0), glm::vec3(0,0,0), glm::vec2(500, 500), glm::vec3(1,1,1), glm::vec2(2,2),0));
	l.push_back(new PointLight(glm::vec3(0,400,0)));
	this->basic.shadowMap->setLights(l);
	basic.imGuiManager->addLight(l[0], "PointLight");
	snow = new Snow(&basic);
	
}

SceneHandlerCalls TestScene::update(float dt)
{
	SceneHandlerCalls theReturn = SceneHandlerCalls::NOTHING;
	static float shouldupdate = 0.01666666667f;
	static float currentupdate = 0;

	currentupdate += dt;
	if (currentupdate >= shouldupdate) {
		currentupdate -= shouldupdate;
		snow->update();
	}
	

	return theReturn;
}

void TestScene::render()
{
	//snow->update();
	snow->render();
}
