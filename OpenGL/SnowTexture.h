#pragma once
#include "BufferCreator.h"
#include <glm.hpp>

class SnowTexture
{
public:
	SnowTexture(glm::vec2 size);
	~SnowTexture();
	uint32_t getTexture();
private:
	uint32_t texture;
	uint32_t g_height;
};