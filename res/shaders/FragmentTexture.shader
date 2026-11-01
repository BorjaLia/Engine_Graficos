#version 330 core

in vec2 v_TexCoord;
in vec4 v_Color;

uniform sampler2D u_texture; 

layout(location = 0) out vec4 color;

void main()
{
    color = texture(u_texture, v_TexCoord) * v_Color;
}