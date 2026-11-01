#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord; 
layout(location = 2) in vec4 color;

out vec2 v_TexCoord;
out vec4 v_Color;

void main()
{
	gl_Position = position;
	v_TexCoord = texCoord;
    v_Color = color;
}