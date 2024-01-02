#include "SnowTexture.h"

SnowTexture::SnowTexture(glm::vec2 size)
{
    glGenFramebuffers(1, &texture);
    glBindFramebuffer(GL_FRAMEBUFFER, texture);

    glGenTextures(1, &g_height);
    glBindTexture(GL_TEXTURE_2D, g_height);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, size.x, size.y, 0, GL_RGBA, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, g_height, 0);
}

SnowTexture::~SnowTexture()
{
}

uint32_t SnowTexture::getTexture()
{
    return uint32_t();
}
