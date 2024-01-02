#include "Billboard.h"
#include "ErrorHelper.h"

BillboardGroup::BillboardGroup(uint32_t nrOfBillboards, uint32_t texture):
	 texture(texture)
{
	std::vector<ParticleVertex> particles;
	this->nrOfBillboards = nrOfBillboards;
	if (nrOfBillboards % 16 != 0)
	{
		this->nrOfBillboards += 16 - (nrOfBillboards % 16);
	}
	particles.reserve(nrOfBillboards);
	for (uint32_t i = 0; i < nrOfBillboards; i++)
	{
		particles.push_back(ParticleVertex(
			glm::vec3(
				(float)(rand() % 800),
				(float)(rand() % 350),
				(float)(rand() % 800)
			),
			glm::vec3(10,10,10)
		));
	}

	this->ParticleArrayBuffer = CreateVertexArray();
	ParticleVBO = CreateParticleBuffer(particles);//TODO : make this dynamic?
}

void BillboardGroup::update()
{
	
	GLTest(glDispatchCompute(nrOfBillboards/16 + 1, 1, 1));
	glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
}

void BillboardGroup::render()
{
	
	glDisable(GL_CULL_FACE);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBindVertexArray(ParticleArrayBuffer);
	glDrawArrays(GL_POINTS, 0, nrOfBillboards);
	glEnable(GL_CULL_FACE);
}
