#version 420 core

in vec4 o_pos[];
in vec3 o_normal[];

layout (points) in;
layout (triangle_strip, max_vertices = 4) out;

out vec3 i_normal;
out vec2 i_uv;


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

void main() {    
    const float size = 0.3;
    mat4 MVP = (transform * view) * projection;

    vec3 upVector = vec3(
        o_normal[0].y + o_normal[0].z,
        o_normal[0].z - o_normal[0].x,
        -o_normal[0].x - o_normal[0].y
    );
    
    i_normal = o_normal[0];

    vec3 rightVector = cross(upVector, i_normal);
    upVector = normalize(upVector) * size;
    rightVector = normalize(rightVector) * size;

    gl_Position = (o_pos[0] - vec4(upVector, 0.0) - vec4(rightVector, 0.0)) * MVP;
    i_uv = vec2(0,0);
    EmitVertex();

    gl_Position = (o_pos[0] - vec4(upVector, 0.0) + vec4(rightVector, 0.0)) * MVP;
    i_uv = vec2(0,1);
    EmitVertex();

    gl_Position = (o_pos[0] + vec4(upVector, 0.0) - vec4(rightVector, 0.0)) * MVP;
    i_uv = vec2(1,0);
    EmitVertex();

    gl_Position = (o_pos[0] + vec4(upVector, 0.0) + vec4(rightVector, 0.0)) * MVP;
    i_uv = vec2(1,1);
    EmitVertex();
    
    EndPrimitive();
}  