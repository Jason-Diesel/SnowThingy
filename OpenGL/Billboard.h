#pragma once
#include "BufferCreator.h"
#include "Vertex.h"


class BillboardGroup
{
public:
	BillboardGroup(uint32_t nrOfBillboards, uint32_t texture);
	void update();
	void render();
private:
	uint32_t nrOfBillboards;
	uint32_t texture;

	uint32_t ParticleArrayBuffer;
	uint32_t ParticleVBO;
};