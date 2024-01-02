#pragma once
#include <glm.hpp>

//Vertex with UV
struct Vertex{
	Vertex(){
	}
	Vertex(glm::vec3 pos, glm::vec2 UV, glm::vec3 normals, glm::vec3 tangent, glm::vec3 bitangent):
		m_position(pos), m_texChoords(UV), m_normals(normals), m_tangent(tangent), m_bitangent(bitangent)
	{
	}
	glm::vec3 m_position;
	glm::vec2 m_texChoords;
	glm::vec3 m_normals;
	glm::vec3 m_tangent;
	glm::vec3 m_bitangent;
	
};

struct ParticleVertex {
	ParticleVertex() {
	}
	ParticleVertex(glm::vec3 pos, glm::vec3 maxVelocity) :
		m_position(pos)
	{
		m_velocity = glm::vec3(
			(float)(rand() % (int)maxVelocity.x * 100) / 100.f,
			(float)(rand() % (int)maxVelocity.y * 100) / 100.f,
			(float)(rand() % (int)maxVelocity.z * 100) / 100.f
		);
		m_normals = glm::vec3(
			(float)(rand() % 200) / 100.f - 1.0f,
			(float)(rand() % 200) / 100.f - 1.0f,
			(float)(rand() % 200) / 100.f - 1.0f
		);
		m_normals = glm::normalize(m_normals);

	}
	glm::vec3 m_position;
	glm::vec3 m_velocity;
	glm::vec3 m_normals;
};

struct AnimationVertex
{
	AnimationVertex(glm::vec3 pos, glm::vec2 UV, glm::vec3 normals, glm::vec3 tangent, glm::vec3 bitangent):
		m_position(pos), m_texChoords(UV), m_normals(normals), m_tangent(tangent), m_bitangent(bitangent)
	{
		m_boneIDs = glm::vec4(-1,-1,-1,-1);
		m_boneWeights = glm::vec4(0,0,0,0);
	}
	glm::vec3 m_position;
	glm::vec2 m_texChoords;
	glm::vec3 m_normals;
	glm::vec3 m_tangent;
	glm::vec3 m_bitangent;

	glm::vec4 m_boneIDs;
	glm::vec4 m_boneWeights;
};
