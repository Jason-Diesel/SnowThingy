#version 420 core
        
layout(location = 0) out vec4 finalPixel;

in vec3 i_normal;
in vec2 i_uv;

//texture materials
layout(binding = 0)uniform sampler2D ambientTexture;

void main()
{ 
    finalPixel = texture(ambientTexture, i_uv);

    if(finalPixel.a > 0){
        finalPixel.a = 0.5;
    }
    else{
        discard;
    }
    
}