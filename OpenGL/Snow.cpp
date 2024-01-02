#include "Snow.h"

Snow::Snow(DefaultVariableToScene* basic):
	snowParticles(50000, basic->rm->getTexture("textures/snowflake.png"))
{
	this->basic = basic;
	glm::vec2 snowTextureSize(800,800);

	snow = basic->gh->createGameObject("snow", false);

	snow->addModel(basic->rm->getModel("Plane.fbx"));

	snow->getComponent<Transform>("Transform")->position.y = 0.1f;
	snow->getComponent<Transform>("Transform")->rotation.y = 3.14f/2.f;
	snow->getComponent<Transform>("Transform")->position.x = 400.f;
	snow->getComponent<Transform>("Transform")->position.z = 400.f;
	snow->getComponent<Transform>("Transform")->scale.x = 400.0f;
	snow->getComponent<Transform>("Transform")->scale.y = 400.0f;

	snow->getMaterial().Albedo = basic->rm->getTexture("textures/SnowTexture.jpg");

	//basic->imGuiManager->addGameObject(plane1, "plane");
	basic->imGuiManager->addGameObject(snow, "Snow");

	glGenTextures(1, &snowHeightTexture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, snowHeightTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, snowTextureSize.x, snowTextureSize.y, 0, GL_RGBA,
		GL_FLOAT, NULL);


	snow->getMaterial().HeightMap = snowHeightTexture;
	snow->getMaterial(0).materialFlags = MaterialFlags(snow->getMaterial(0).materialFlags | MaterialFlags::HeightMap);
	snow->SetShaderProgram(basic->rm->getShaderProgram("DefTessellation"));

	billboardShader = basic->rm->createShaderProgram("SnowParticle",
		basic->rm->getShader("BillboardVertex.vert"),
		basic->rm->getShader("BillboardGeometry.geom"),
		basic->rm->getShader("Billboardfragment.frag")
	);
	
}

void Snow::update()
{
	basic->shaderHandler->setCurrentshader(basic->rm->getShader("SnowCompute.comp"));
	glBindImageTexture(0, snowHeightTexture, 0, GL_FALSE, 0, GL_READ_WRITE, GL_RGBA32F);
	snowParticles.update();
}

void Snow::render()
{
	basic->shaderHandler->setCurrentshader(billboardShader);
	snowParticles.render();
}
