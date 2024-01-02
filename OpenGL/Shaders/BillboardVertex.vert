#version 420 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 velocity;//Can I not care about this guy?
layout(location = 2) in vec3 normal;

out vec4 o_pos;
out vec3 o_normal;

layout (std140, binding = 0) uniform Matrices
{
    mat4 projection;
    mat4 view;
	vec4 cameraPos;
};

layout (std140, binding = 1) uniform Transform
{
    mat4 transform;
};

const int MAXNUMBEROFLIGHTS = 6;
layout (std140, binding = 3) uniform ShadowData
{
    vec4 lightPos[MAXNUMBEROFLIGHTS];//4:th element is what type of light it is
	vec4 lightColors[MAXNUMBEROFLIGHTS];//4:th element is how hard the shadows should be
	mat4 lightViewProjection[MAXNUMBEROFLIGHTS];
	int nrOfLight;
};

void main()
{
	//gl_Position = vec4(position.xyz, 1.0);
	o_pos = vec4(position.xyz, 1.0);
	o_normal = normalize((vec4(normal, 0.0) * transform).xyz);
}